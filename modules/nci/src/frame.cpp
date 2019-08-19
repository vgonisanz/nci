#include "frame.h"

#include <ncurses.h>
#include <sstream>

#include "utils.h"

namespace nci
{

Frame::Frame(std::string id, Point2D origin, Size2D size)
{
    _has_border = true;
    _id = id;


    std::cout << "Create frame: " << _id
        << " origin (" << origin.x << ", " << origin.y << ")"
        << " size (" << size.width << ", " << size.height << ")"
        << std::endl;

    if(_has_border)
    {
        _border = newwin(size.height, size.width, origin.y, origin.x);

        if(_border == nullptr)
            std::cout << "Warning: border created is a nullptr, maybe not call initscr before create Frame" << std::endl;

            /* TODO PROPER OPERATOR */
        //size -= 1;
        //origin += 1;
        size.width -= 2;
        size.height -= 2;
        origin.x += 1;
        origin.y += 1;
/*
        std::cout << "Create frame: " << _id
    << " origin (" << origin.x << ", " << origin.y << ")"
    << " size (" << size.width << ", " << size.height << ")"
    << std::endl;
*/
    }

    _content = newwin(size.height, size.width, origin.y, origin.x);

    if(_content == nullptr)
        std::cout << "Warning: border created is a nullptr, maybe not call initscr before create Frame" << std::endl;
}

Frame::~Frame()
{
    std::cout << "Destroying frame: " << _id << std::endl;

    if(_has_border)
        delwin(_border);
    delwin(_content);
}

void Frame::draw()
{
    std::cout << "draw: " << _id << std::endl;
    box_me();
    wrefresh(_content);
    _children.draw();
}

void Frame::move(Point2D origin)
{
    Point2D original = get_origin();
    std::cout << "move: " << _id
        << " from (" << original.x << "," << original.y << ")"
        << " to (" << origin.x << "," << origin.y << ")"
        << std::endl;
    if(_has_border)
    {
        mvwin(_border, origin.y, origin.x);
        origin.x += 1;
        origin.y += 1;
    }
    mvwin(_content, origin.y, origin.x);
}

void Frame::resize(Size2D size)
{
    Size2D original = get_size();
    std::cout << "resize: " << _id
        << " from (" << original.width << "," << original.height << ")"
        << " to (" << size.width << "," << size.height << ")"
        << std::endl;
    if(_has_border)
    {
        wresize(_border, size.height, size.width);
        size.width -= 2;
        size.height -= 2;
    }
    wresize(_content, size.height, size.width);
}

void Frame::run()
{
    std::cout << "run: " << _id << std::endl;
}

void Frame::set_background_color(int color_id)
{
    wbkgd(_content, COLOR_PAIR(color_id));

    for(auto child: _children)
        child->set_background_color(color_id);
}

void Frame::box_me()
{
    if(!_has_border)
        return;

    box(_border);
    wrefresh(_border);
}
/*
void Frame::set_border(bool value)
{
    _has_border = value;
}*/

} /* namespace nci */
