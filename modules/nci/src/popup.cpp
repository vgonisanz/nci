#include "popup.h"

#include <ncurses.h>
#include <sstream>

#include "imanager.h"
#include "utils.h"

namespace nci
{

Popup::Popup(std::string id, std::string text):
Frame(id, Point2D(0, 0), Size2D(1, 1))
{
    std::cout << "Create Popup: " << _id << std::endl;

    Size2D size = nci::IManager::get_size();
    move(Point2D(size.width/4, size.height/4));
    resize(Size2D(size.width/2, size.height/2));
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
    //box(_win, 0, 0);

    Point2D position = get_origin();
    Size2D size = get_size();

    Point2D title_pos(1, 1);
    Point2D text_pos(1, 1);
    Size2D text_size(0, 0);

    /* Draw title */
    top_box(_title_win, _id);
    mvwaddstr(_title_win, title_pos.y, title_pos.x, _title.c_str());
    wrefresh(_title_win);

    /* Draw body */
    text_size.height = getmaxy(_text_win);
    bot_box(_text_win, _id);
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

void Popup::set_background_color(int color_id)
{
    wbkgd(_title_win, COLOR_PAIR(color_id));
    wbkgd(_text_win, COLOR_PAIR(color_id));

}

} /* namespace nci */
