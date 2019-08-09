#include "frame.h"

#include <ncurses.h>
#include <sstream>

namespace nci
{

Frame::Frame(std::string id, Point2D origin, Size2D size)
{
    _id = id;
    _origin = origin;
    _size = size;

    std::cout << "Create frame: " << _id << std::endl;

    _win = newwin(_size.height, _size.width, _origin.y, _origin.x);

    if(_win == nullptr)
        std::cout << "Warning: win created is a nullptr, maybe not call initscr before create Frame" << std::endl;
}

Frame::~Frame()
{
    std::cout << "Destroying frame: " << _id << std::endl;
    delwin(_win);
}

void Frame::draw()
{
    std::cout << "draw: " << _id << std::endl;
    box(_win, 0, 0);
    wrefresh(_win);
}

void Frame::run()
{
    std::cout << "run: " << _id << std::endl;
}

void Frame::set_background_color(int color_id)
{
    wbkgd(_win, COLOR_PAIR(color_id));
}

} /* namespace nci */
