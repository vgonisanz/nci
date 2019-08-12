#include "textFrame.h"

#include <ncurses.h>
#include <sstream>

namespace nci
{

TextFrame::TextFrame(std::string id, Point2D origin, Size2D size):
_text("")
{
    _id = id;
    _origin = origin;
    _size = size;

    std::cout << "Create text frame: " << _id << std::endl;

    _win = newwin(_size.height, _size.width, _origin.y, _origin.x);

    if(_win == nullptr)
        std::cout << "Warning: win created is a nullptr, maybe not call initscr before create TextFrame" << std::endl;
}

TextFrame::~TextFrame()
{
    std::cout << "Destroying frame: " << _id << std::endl;
    delwin(_win);
}

void TextFrame::draw()
{
    std::cout << "draw: " << _id << std::endl;

    mvaddstr(0, 0, _id.c_str());
    wrefresh(_win);
}

void TextFrame::run()
{
    std::cout << "run: " << _id << std::endl;
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
