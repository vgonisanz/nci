#include "frame.h"

#include <ncurses.h>
#include <sstream>

#include "utils.h"

namespace nci
{

Frame::Frame(std::string id, Point2D origin, Size2D size)
{
    _runnable = false;
    _has_border = true;
    _id = id;
    _background_color = 0;

    create(origin, size);
}

Frame::~Frame()
{
    std::cout << "Destroying frame: " << _id << std::endl;

    destroy();
}

void Frame::create(Point2D origin, Size2D size)
{
    std::cout << "Create frame: " << _id
        << " origin (" << origin.x << ", " << origin.y << ")"
        << " size (" << size.width << ", " << size.height << ")"
        << std::endl;

    if(_has_border)
    {
        _border = newwin(size.height, size.width, origin.y, origin.x);

        if(_border == nullptr)
            std::cout << "Warning: border created is a nullptr, maybe not call initscr before create Frame" << std::endl;

        size -= 2;
        origin += 1;
    }

    _content = newwin(size.height, size.width, origin.y, origin.x);

    if(_content == nullptr)
        std::cout << "Warning: border created is a nullptr, maybe not call initscr before create Frame" << std::endl;
}

void Frame::destroy()
{
    if(_has_border)
        delwin(_border);
    delwin(_content);
}

void Frame::draw()
{
    std::cout << "draw: " << _id << std::endl;

    color_me();
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
        size -= 2;
    }
    wresize(_content, size.height, size.width);
}

void Frame::run()
{
    std::cout << "run: " << _id << std::endl;

    if(!_runnable)
        return;
}

void Frame::set_background_color(int color_id)
{
    _background_color = color_id;
}

void Frame::box_me()
{
    if(!_has_border)
        return;

    box(_border);
    wrefresh(_border);
}

void Frame::color_me()
{
    if(_has_border)
        wbkgd(_border, COLOR_PAIR(_background_color));
    wbkgd(_content, COLOR_PAIR(_background_color));
}


Point2D Frame::get_origin() const
{
    Point2D origin;
    if(_has_border)
        getbegyx(_border, origin.y, origin.x);
    else
        getbegyx(_content, origin.y, origin.x);
    return origin;
}

Size2D Frame::get_size() const
{
    Size2D size;
    if(_has_border)
        getmaxyx(_border, size.height, size.width);
    else
        getmaxyx(_content, size.height, size.width);
    return size;
}

Point2D Frame::get_border_origin() const
{
    Point2D origin;
    if(_has_border)
        getbegyx(_border, origin.y, origin.x);
    return origin;
}

Size2D Frame::get_border_size() const
{
    Size2D size;
    if(_has_border)
        getmaxyx(_border, size.height, size.width);
    return size;
}

void Frame::set_border(bool value)
{
    destroy();

    Point2D origin;
    Size2D size;

    if(_has_border)
    {
        origin = get_border_origin();
        size = get_border_size();
    }
    else
    {
        origin = get_origin();
        size = get_size();
    }

    _has_border = value;
    create(origin, size);
}

void Frame::set_runnable(bool runnable)
{
    std::cout << "Setting " << _id << " runnable: " << runnable << std::endl;
    _runnable = runnable;
}

void Frame::keybind(int character, std::function<void()> function)
{
    _keys.add(character, function);
}

} /* namespace nci */
