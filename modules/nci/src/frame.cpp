#include "frame.h"

#include <ncurses.h>
#include <sstream>

namespace nci
{

Frame::Frame(std::string id, Point2D origin, Size2D size)
{
    _id = id;

    std::cout << "Create frame: " << _id
        << " origin (" << origin.x << ", " << origin.y << ")"
        << " size (" << size.width << ", " << size.height << ")"
        << std::endl;

    _win = newwin(size.height, size.width, origin.y, origin.x);

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
    _children.draw();
}

void Frame::move(Point2D origin)
{
    Point2D original = get_origin();
    std::cout << "move: " << _id
        << " from (" << original.x << "," << original.y << ")"
        << " to (" << origin.x << "," << origin.y << ")"
        << std::endl;
    mvwin(_win, origin.y, origin.x);
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
