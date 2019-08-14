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

void Popup::resize(Size2D size)
{
    Frame::resize(size);
    delwin(_title_win);
    delwin(_text_win);

    Point2D origin = get_origin();

    const uint8_t title_height = 3;

    _title_win = newwin(title_height, size.width, origin.y, origin.x);
    if(_title_win == nullptr)
        std::cout << "Warning: win created is a nullptr, maybe not call initscr before create Frame" << std::endl;

    _text_win = newwin(size.height - title_height, size.width, origin.y + title_height, origin.x);
    if(_text_win == nullptr)
        std::cout << "Warning: win created is a nullptr, maybe not call initscr before create Frame" << std::endl;

}

void Popup::draw()
{
    std::cout << "draw: " << _id << std::endl;
    box(_win, 0, 0);

    Point2D position = get_origin();
    Size2D size = get_size();

    Point2D title_pos(1, 1);
    Point2D text_pos(1, 1);
    Size2D text_size(0, 0);

    /* Draw title */
    box(_title_win, 0, 0);
    mvwaddstr(_title_win, title_pos.y, title_pos.x, _title.c_str());
    wrefresh(_title_win);

    /* Draw body */
    text_size.height = getmaxy(_text_win);
    box(_text_win, 0, 0);
    mvwaddstr(_text_win, text_size.height/2, text_pos.x, _text.c_str());
    wrefresh(_text_win);
    //wrefresh(_win);
    //refresh();
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

void Popup::set_title(std::string title)
{
    _title = title;
}

void Popup::set_text(std::string text)
{
    _text = text;
}

} /* namespace nci */
