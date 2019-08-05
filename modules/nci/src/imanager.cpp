#include "imanager.h"

#include <sstream>

namespace nci
{

WINDOW* IManager::_stdscr = nullptr;

IManager::IManager():
_end_execution(false),
_ch('a')
{
    printf("Initializing IManager");

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
            init_pair(1, COLOR_RED, COLOR_BLACK);
            init_pair(2, COLOR_CYAN, COLOR_BLACK);
    }
}

IManager::~IManager()
{
    endwin();
    //printf("Destroying IManager");
}

void IManager::init()
{
    printw("Hello World !!!");
	refresh();
	getch();
}

/*
void IManager::add_frame(std::shared_ptr<Frame> frame)
{
    frame->set_notify(std::bind(&IManager::redraw, this));
    _frames.push_back(frame);
}
*/
/*
Rect IManager::get_size()
{
    Rect size;
    getbegyx(_stdscr, size.y, size.x);
    getmaxyx(_stdscr, size.height, size.width);
    return size;
}
*/
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
        waddstr(_stdscr, "\n\t\tNumber of colors: ");
        attron(COLOR_PAIR(1));
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
    //for (auto &frame : _frames)
    //    frame->draw_win();
}

/*
bool IManager::run()
{
    if (_frames.empty())
        return false;

    int current = -1;
    bool execute = false;

    attron(COLOR_PAIR(2));
    printw("Press Q to exit\n");
    refresh();
    attroff(COLOR_PAIR(2));

    redraw();

    while(_end_execution == false)
    {
        current += 1;
        current = current % _frames.size();
        if (current < 0)
            current = 0;
        if (current >= _frames.size())
            current = _frames.size() - 1;

        std::stringstream msg;
        msg << "Running frame: " << current;
        mvaddstr(0, 0, msg.str().c_str());

        _frames.at(current)->run();
        _ch = getch();
        switch(_ch)
        {
            case 'q':
                _end_execution = true;
                mvaddstr(0, 0, "User end execution. Push any button...");
                getch();
                break;
            default:
                break;
        }
    }

    return true;
}
*/
void IManager::test()
{

}

} /* namespace nci */
