#include "button.h"

#include <ncurses.h>
#include <sstream>

#include "nci.h"
#include <string> 
#include "utils.h"
#include "popup.h"
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include<stdlib.h>

namespace nci
{

Button::Button(std::string id, Point2D origin, Size2D size):
Frame(id, origin, size, false),
_text_frame(std::string(size.width * size.height, KEYS::SPACE)),
_ok_function(NULL)
{
    std::cout << "Create button: " << _id << std::endl;
    keybind('\n',std::bind(&Button::pressed_ok,this));
}

Button::~Button()
{
    std::cout << "Destroying button: " << _id << std::endl;
}

void Button::draw()
{
    Point2D origin = get_origin();
    std::cout << "draw: " << _id << " at (" << origin.x << ", " << origin.y << ")" << std::endl;
    

    wclear(_content);
    box_me();
    border_selected();
    color_me();

    /* Relative drawing to win */
    Point2D init_pos = cursor_get_position();
    mvwaddstr(_content, 0, 0, _text_frame.get_text().c_str());
    wrefresh(_content);
    cursor_set_position(init_pos);
}

void Button::invert_draw(unsigned int animation_delay_in_us)
{
    wrefresh(_border);

    /* Relative drawing to win */
    //Point2D init_pos = cursor_get_position();
    mvwaddstr(_content, 0, 0, _text_frame.get_text().c_str());
    wbkgd(_content, A_REVERSE);
    wrefresh(_content);

    usleep(animation_delay_in_us);

    draw();
}

void Button::run()
{
    std::cout << "run: " << _id << std::endl;

    if(!_runnable)
    {
        std::cout << _id << " is not runnable" << std::endl;
        return;
    }
    set_selected(true);
    draw();

    for(auto child: _children)
        child->run();
    _keys.run();

    set_selected(false);
    draw();
}

void Button::set_text(std::string text)
{
    _text_frame.set_text(text);
    cursor_set_position(_text_frame.get_text().size());
    _text_frame.get_text().resize(_text_frame.get_text().capacity(), KEYS::SPACE); /* fill whole window with spaces */
}

std::string Button::get_text()
{
    return _text_frame.get_text();
}

void Button::set_selected(bool highlight)
{
    _is_selected = highlight;
}

bool Button::get_selected() const
{
    return _is_selected;
}

void Button::border_selected()
{
    if(get_selected())
        wbkgd(_border, A_REVERSE);
    else
        color_me();
    
    wrefresh(_border);

}

void Button::set_pressed_ok_callback(std::function<void()> function)
{
    _ok_function = function;
}

void Button::pressed_ok()
{
    std::cout << "Funcion privada pressed ok" << std::endl;
    if(_ok_function)
    {
        std::cout << "Dentro del ok" << std::endl;
        preprocess();
        _ok_function();
        postprocess();
    }  
}

void Button::preprocess()
{
    invert_draw();
   
}

void Button::postprocess()
{
    std::cout << "Funcion de POSTprocesado del boton" << std::endl;
}

} /* namespace nci */
