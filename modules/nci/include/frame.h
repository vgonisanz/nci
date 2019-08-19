/**
 * @file            frame.h
 * @version         1.0
 * @date            August 2019
 * @brief           Main nci workspace.
 * @author          vgonisanz
 *
 * Pure virtual Frame base class
 *
 * @license LGPL v3.0
 */
#ifndef __FRAME_HEADER_FILE_H
#define __FRAME_HEADER_FILE_H

#include <ncurses.h>

#include "types.h"
#include "virtualFrame.h"
#include "frameContainer.h"

namespace nci
{

class Frame : public VirtualFrame
{
public:
    Frame(std::string id, Point2D origin = Point2D(0, 0), Size2D size = Size2D(1, 1));
    ~Frame();

    Point2D get_origin() const
    {
        Point2D origin;
        if(_has_border)
            getbegyx(_border, origin.y, origin.x);
        else
            getbegyx(_content, origin.y, origin.x);
        return origin;
    }

    Size2D get_size() const
    {
        Size2D size;
        if(_has_border)
            getmaxyx(_border, size.height, size.width);
        else
            getmaxyx(_content, size.height, size.width);
        return size;
    }

    virtual void draw();
    virtual void run();

    virtual void move(Point2D origin);
    virtual void resize(Size2D size);

    virtual void set_background_color(int color_id);
    virtual void box_me();

    //void set_border(bool value);
};

}   // namespace nci
#endif  /* __FRAME_HEADER_FILE_H */
