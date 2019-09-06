#include "textFrame.h"

#include <ncurses.h>
#include <sstream>

#include "nci.h"

namespace nci
{

TextFrame::TextFrame(std::string id, Point2D origin, Size2D size):
Frame(id, origin, size, false),
_text(""),
_editable(false)
{
    std::cout << "Create text frame: " << _id << std::endl;

    //_border = newwin(size.height, size.width, origin.y, origin.x);

    //if(_border == nullptr)
    //    std::cout << "Warning: win created is a nullptr, maybe not call initscr before create TextFrame" << std::endl;

    keybind('e', std::bind(&TextFrame::edit_mode, this));
}

TextFrame::~TextFrame()
{
    std::cout << "Destroying frame: " << _id << std::endl;
    //delwin(_border);
}

void TextFrame::draw()
{
    Point2D origin = get_origin();
    std::cout << "draw: " << _id << " at (" << origin.x << ", " << origin.y << ")" << std::endl;

    //box_me();
    color_me();

    /* Relative drawing to win */
    mvwaddstr(_content, 0, 0, _text.c_str());
    wrefresh(_content);
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
    set_cursor(_text.size());
}

std::string TextFrame::get_text()
{
    return _text;
}

void TextFrame::set_editable(bool edit)
{
    _runnable = edit;
    _editable = edit;
}

void TextFrame::edit_mode()
{
    std::cout << "edit_mode: " << _id << std::endl;
    feedback_ncurses(true);
    Point2D position = get_cursor();
    mvwgetstr(_content, position.y, position.x, const_cast<char*>(_text.c_str()));
    feedback_ncurses(false);
}

} /* namespace nci */
