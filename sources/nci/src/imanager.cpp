#include "imanager.h"

#include "frameContainer.h"
#include "nci.h"
#include "virtualFrame.h"

#include <ctime>
#include <ncurses.h>
#include <vector>

namespace nci
{

WINDOW* IManager::_stdscr = nullptr;
bool IManager::_initialized = false;
FrameContainer IManager::_children;
std::streambuf* IManager::_coutbuf = nullptr;
std::string IManager::_log_filename = "log.txt";

IManager::IManager(std::string log_path):
_logstream(),
_end_execution(false),
_ch(-1)
{
    /* ncurses initialization */
    if(_initialized)
        throw std::runtime_error("You shall not create several IManagers");

    _stdscr = initialize_ncurses();
    
    /* Redirect std::cout to a timestamp file log */
    time_t current_time;
    struct tm * time_info;
    char buffer[80];

    time(&current_time);
    time_info = localtime(&current_time);

    strftime(buffer, sizeof(buffer),"%Y-%m-%d-%H-%M-%S", time_info);
    _log_filename = log_path + "/log-" + std::string(buffer) + ".txt";
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

    _initialized = true;
}

IManager::~IManager()
{
    abort();
}

void IManager::init()
{
}

Size2D IManager::get_size()
{
    Size2D size(0, 0);

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
    _children.draw();
    //for (auto &frame : _frames)
    //    frame->draw();
}

void IManager::clear_window()
{
    clear();
}

bool IManager::run()
{
    if (_children.empty())
        return false;

    std::cout << "IManager start running frames..." << std::endl;

    int current = -1;

    redraw();
    
    while(_end_execution == false)
    {
        std::cout << " DENTRO DEL BUCLE MANAGER" << std::endl;
        current += 1;
        current = current % _children.size();
        if (current < 0)
            current = 0;
        if (current >= _children.size())
            current = _children.size() - 1;

        std::cout << "Running frame: " << current << std::endl;
    
        _children.at(current)->run();
    }
    std::cout << " SALIDA DEL BUCLE MANAGER" << std::endl;
    return true;
}

void IManager::execute_key_if_exist(int character)
{
    std::cout <<"----------->>>>>>>>>>>>>>>>>>>>> execute key exist" << std::endl;
    //Estos if hay que modificarlos por algo mas general y escalable
    if( KEYS::ESCAPE == character)
     {
        std::cout <<"----------->>>>>>>>>>>>>>>>>>>>> Abortar" << std::endl;
        abort();
     }  
     else if(KEYS::ENTER == character)
     {
         std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ENTER <<<<<<<<<<< " << std::endl;
         clear_window();
     }
}

void IManager::abort()
{
   tear_down_ncurses();

    /* "free" smart pointers */
    _children.clear();

    /* Restore std::cout */
    std::cout.rdbuf(_coutbuf);
    //std::filesystem::copy(_log_filename, "last_log.txt");

    std::cout << "Log generated at: " << _log_filename << std::endl; 
    exit(0);
}

} /* namespace nci */
