#include "textFrame.h"

#include <ncurses.h>
#include <sstream>

namespace nci
{

TextFrame::TextFrame(std::string id, Point2D origin, Size2D size):
Frame(id, origin, size),
_text("")
{
    std::cout << "Create text frame: " << _id << std::endl;

    _border = newwin(size.height, size.width, origin.y, origin.x);

    if(_border == nullptr)
        std::cout << "Warning: win created is a nullptr, maybe not call initscr before create TextFrame" << std::endl;
}

TextFrame::~TextFrame()
{
    std::cout << "Destroying frame: " << _id << std::endl;
    delwin(_border);
}

void TextFrame::draw()
{
    Point2D origin = get_origin();
    std::cout << "draw: " << _id << " at (" << origin.x << ", " << origin.y << ")" << std::endl;

    /* Relative drawing to win */
    mvwaddstr(_border, 0, 0, _text.c_str());
    wrefresh(_border);
}

void TextFrame::run()
{
    std::cout << "run: " << _id << std::endl;

    if(!_runnable)
    {
        std::cout << _id << " is not runnable" << std::endl;
        return;
    }

    _keys.run();
}

void TextFrame::set_text(std::string text)
{
    _text = text;
}

std::string TextFrame::get_text()
{
    return _text;
}

} /* namespace nci */
