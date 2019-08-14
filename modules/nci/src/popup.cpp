#include "popup.h"

#include <ncurses.h>
#include <sstream>

namespace nci
{

Popup::Popup(std::string id, std::string text):
Frame(id, Point2D(0, 0), Size2D(1, 1))
{
    std::cout << "Create Popup: " << _id << std::endl;

    //uint16_t x, y, width, height;
    //getbegyx(_stdscr, y, x);
    //getmaxyx(_stdscr, height, width);
    //width = screen.width;
    //height = ROWS;
}

Popup::~Popup()
{
    std::cout << "Destroying Popup: " << _id << std::endl;
    delwin(_win);
}

void Popup::draw()
{
    std::cout << "draw: " << _id << std::endl;
    box(_win, 0, 0);
    wrefresh(_win);
    refresh();
}

void Popup::run()
{
    std::cout << "run: " << _id << std::endl;

    uint16_t ch = -1;
    bool end_execution = false;

    draw();

    while(end_execution == false)
    {
        ch = getch();
        std::cout << "User input: " << ch << std::endl;
        switch(ch)
        {
            case 'q':
                end_execution = true;
                wclear(_win);
                break;
            default:
                break;
        }
    }
}

void Popup::set_text(std::string text)
{

}

} /* namespace nci */
