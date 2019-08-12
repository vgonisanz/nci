#include "imanager.h"

#include <ctime>
#include <filesystem>

namespace nci
{

WINDOW* IManager::_stdscr = nullptr;

IManager::IManager():
_logstream(),
_end_execution(false),
_ch(-1)
{
    /* ncurses initialization */
    _stdscr = initscr();
    raw();				            /* Line buffering disabled */
	keypad(stdscr, TRUE);	        /* We get F1, F2... */
	noecho();			            /* Don't echo() while we do getch */
    curs_set(CURSOR::INVISIBLE);
    if (has_colors())
    {
        start_color();                  /* Allow color */
        //use_default_colors();           /* Default colors */
        if (can_change_color())         // TODO pallete colors
        {
            init_pair(1, COLOR_RED, COLOR_BLACK);
            init_pair(2, COLOR_CYAN, COLOR_BLACK);
            init_pair(3, COLOR_WHITE, COLOR_RED);
            init_pair(4, COLOR_WHITE, COLOR_BLUE);
            init_pair(5, COLOR_WHITE, COLOR_GREEN);
            init_pair(6, COLOR_WHITE, COLOR_MAGENTA);
        }
    }

    /* Redirect std::cout to a timestamp file log */
    time_t current_time;
    struct tm * time_info;
    char buffer[80];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(buffer, sizeof(buffer),"%Y-%m-%d-%H-%M-%S", time_info);
    _log_filename = std::string(buffer) + "-log.txt";
    _logstream.open(_log_filename, std::ofstream::out | std::ofstream::app);
    _coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(_logstream.rdbuf());

    /* Log terminal info */
    const Size2D size = get_size();
    std::cout << "Has color?: " << (has_colors() ? std::string("true") : "false") << std::endl;
    std::cout << "Colors: " << std::to_string(COLORS)
        << ", pairs: " << std::to_string(COLOR_PAIRS) << std::endl;
    std::cout << "Size: " << size.width << "x" << size.height << "." << std::endl;
    std::cout << "Baud rate: " << baudrate() << std::endl;
}

IManager::~IManager()
{
    /* Ncurses tear down */
    waddstr(_stdscr, "\nDestroying frontend. Push a key to continue");
    noraw();
    getch();
    endwin();

    /* "free" smart pointers */
    _frames.clear();

    /* Restore std::cout */
    std::cout.rdbuf(_coutbuf);
    //std::filesystem::copy(_log_filename, "last_log.txt");
}

void IManager::init()
{
}

Size2D IManager::get_size()
{
    Size2D size;
    //getbegyx(_stdscr, size.y, size.x);
    getmaxyx(_stdscr, size.height, size.width);
    return size;
}

void IManager::info()
{
    std::stringstream color_stream;
    color_stream << "\n\t\t" << "Has color?: " << (has_colors() ? std::string("true") : "false");

    std::stringstream size_stream;
    int max_row, max_col;
    getmaxyx(_stdscr, max_row, max_col);
    size_stream << "\n\t\tSize: " << max_row << " rows, " << max_col << " cols";

    std::stringstream baud_rate_stream;
    baud_rate_stream << "\n\t\tBaud rate: " << baudrate();

    werase(_stdscr);
    waddstr(_stdscr, "\n\tTerminal info:");
    waddstr(_stdscr, color_stream.str().c_str());
    if (has_colors())
    {
        waddstr(_stdscr, "\n\t\tNumber of colors and pairs: ");
        attron(COLOR_PAIR(1));
        waddstr(_stdscr, std::to_string(COLORS).c_str());
        waddstr(_stdscr, ", ");
        waddstr(_stdscr, std::to_string(COLOR_PAIRS).c_str());
        attroff(COLOR_PAIR(1));
    }
    waddstr(_stdscr, size_stream.str().c_str());
    waddstr(_stdscr, baud_rate_stream.str().c_str());
    waddstr(_stdscr, "\n\n\tPush a key to continue...");
    getch();
}

void IManager::redraw()
{
    clear();
    refresh();

    /* Draw all frames */
    for (auto &frame : _frames)
        frame->draw();
}

void IManager::add_frame(std::shared_ptr<VirtualFrame> frame)
{
    //frame->set_notify(std::bind(&IManager::redraw, this));
    _frames.push_back(frame);
}

bool IManager::run()
{
    if (_frames.empty())
        return false;

    std::cout << "IManager start running frames..." << std::endl;

    int current = -1;

    while(_end_execution == false)
    {
        current += 1;
        current = current % _frames.size();
        if (current < 0)
            current = 0;
        if (current >= _frames.size())
            current = _frames.size() - 1;

        std::cout << "Running frame: " << current << std::endl;
        _frames.at(current)->run();

        redraw();   /* It is really needed? TODO */
        _ch = getch();
        switch(_ch)
        {
            case 'q':
                _end_execution = true;
                clear();
                mvaddstr(0, 0, "User end execution. Push any button...");
                getch();
                break;
            default:
                break;
        }
    }
    return true;
}

void IManager::test()
{

}

} /* namespace nci */
