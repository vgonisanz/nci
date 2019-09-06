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
    cursor_set_position(_text.size());
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
    Point2D position = cursor_get_position();

    int ch;
    bool exit = false;

    while(ch = wgetch(_content))
    {
        cursor_get_position();

        switch (ch)
        {
            case KEY_LEFT:
                position = cursor_left();
                break;
            case KEY_RIGHT:
                position = cursor_right();
                break;
            case KEY_UP:
                position = cursor_up();
                break;
            case KEY_DOWN:
                position = cursor_down();
                break;
            case KEY_BACKSPACE:
                position = cursor_left();
                wdelch(_content);
                break;
            case 10: /* Enter */
                std::cout << "KEY_ENTER" << std::endl;
                exit = true;
                break;
            case 27: /* Escape */
                std::cout << "KEY_EXIT" << std::endl;
                exit = true;
                break;
            default:
                waddch(_content, ch);
                //position = cursor_right();
                beep();
                break;
        }
        std::cout << "ch " << ch << std::endl;

        if(exit)
            break;
    }
    feedback_ncurses(false);
}

} /* namespace nci */
