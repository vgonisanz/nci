#include "frame.h"

#include <ncurses.h>
#include <sstream>

namespace nci
{

Frame::Frame()
{
    create();
}

Frame::~Frame()
{
    destroy();
}

void Frame::create()
{
    //_win = newwin(_rect.height, _rect.width, _rect.y, _rect.x);
    _win = newwin(2, 2, 0, 0);
}

void Frame::destroy()
{
    delwin(_win);
}

void Frame::draw()
{
    wborder(_win, '|', '|', '-', '-', '+', '+', '+', '+');
    //std::stringstream msg;
    //msg << "HI";
    //mvaddstr(0, 0, msg.str().c_str());
    wrefresh(_win);
    //refresh();
}

void Frame::run()
{
    draw();
}

} /* namespace nci */
