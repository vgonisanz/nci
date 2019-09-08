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
    _text.reserve(size.width * size.height);
    keybind('e', std::bind(&TextFrame::edit_mode, this));
}

TextFrame::~TextFrame()
{
    std::cout << "Destroying textframe: " << _id << std::endl;
}

void TextFrame::draw()
{
    Point2D origin = get_origin();
    std::cout << "draw: " << _id << " at (" << origin.x << ", " << origin.y << ")" << std::endl;

    box_me();
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
    add_attribute(A_REVERSE);
    draw();
    apply_attributes();

    Point2D position = cursor_get_position();

    int ch;
    bool exit = false;

    while(ch = wgetch(_content))
    {
        switch (ch)
        {
            case KEYS::I_KEY_LEFT:
                position = cursor_left();
                break;
            case KEYS::I_KEY_RIGHT:
                position = cursor_right();
                break;
            case KEYS::I_KEY_UP:
                position = cursor_up();
                break;
            case KEYS::I_KEY_DOWN:
                position = cursor_down();
                break;
            case KEYS::I_KEY_BACKSPACE:
                position = cursor_left();
                _text[position.y * position.x + position.x] = ' ';
                wdelch(_content);
                break;
            case KEYS::ENTER:
                std::cout << "KEY_ENTER" << std::endl;
                exit = true;
                break;
            case KEYS::ESCAPE:
                std::cout << "KEY_EXIT" << std::endl;
                exit = true;
                break;
            default:
                if(ch >= KEYS::SPACE && ch <= KEYS::TILDE)
                {
                    position = cursor_right(false); /* update object cursor */
                    waddch(_content, ch);
                    _text[position.y * position.x + position.x - 1] = ch;
                }
                beep();
                break;
        }

        /* exit if required */
        if(exit)
        {
            /* Update cursor with latest position */
            cursor_set_position(position);
            break;
        }
    }

    remove_attribute(A_REVERSE);
    unapply_attributes(); /* TODO ugly here */
    draw();
    feedback_ncurses(false);
}

} /* namespace nci */
