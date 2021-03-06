#include "textFrame.h"

#include <ncurses.h>
#include <sstream>

#include "nci.h"

namespace nci
{

TextFrame::TextFrame(std::string id, Point2D origin, Size2D size):
Frame(id, origin, size, false),
_text(std::string(size.width * size.height, KEYS::SPACE)),
_editable(false)
{
    std::cout << "Create text frame: " << _id << std::endl;

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

    wclear(_content);
    box_me();
    color_me();

    /* Relative drawing to win */
    Point2D init_pos = cursor_get_position();
    mvwaddstr(_content, 0, 0, _text.c_str());
    wrefresh(_content);
    cursor_set_position(init_pos);
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
    _text.resize(_text.capacity(), KEYS::SPACE); /* fill whole window with spaces */
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
    const Size2D size = get_size();

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
                _text[position.y * size.width + position.x] = KEYS::SPACE;
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
                    waddch(_content, ch);
                    _text[position.y * size.width + position.x] = ch;
                    position = cursor_get_position();
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
