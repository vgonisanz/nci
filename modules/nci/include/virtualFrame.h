/**
 * @file            virtualFrame.h
 * @version         1.0
 * @date            August 2019
 * @brief           Main nci workspace.
 * @author          vgonisanz
 *
 * Pure virtual Frame base class
 *
 * @license LGPL v3.0
 */
#ifndef __VIRTUALFRAME_HEADER_FILE_H
#define __VIRTUALFRAME_HEADER_FILE_H

#include <ncurses.h>
#include <iostream>

#include "types.h"
#include "frameContainer.h"

namespace nci
{

class VirtualFrame
{
protected:
    WINDOW *_border;
    WINDOW *_content;

    std::string _id;
    FrameContainer _children;

    bool _has_border;

public:
    VirtualFrame() {};
    virtual ~VirtualFrame() {};

    virtual void draw() = 0;
    virtual void run() = 0;

    template <typename F>
    void add(F frame)
    {
        Point2D origin;
        getbegyx(_border, origin.y, origin.x);
        _children.add(frame, origin);
    }

    virtual void set_background_color(int color_id) = 0;
};

}   // namespace nci
#endif  /* __VIRTUALFRAME_HEADER_FILE_H */
