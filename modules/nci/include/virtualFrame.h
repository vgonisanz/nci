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

#include "types.h"

namespace nci
{

class VirtualFrame
{
protected:
    WINDOW *_win;
    Point2D _origin;
    Size2D _size;

protected:
    virtual void create() = 0;
    virtual void destroy() = 0;

public:
    VirtualFrame() {};
    virtual ~VirtualFrame() {};

    virtual void draw() = 0;
    virtual void run() = 0;
};

}   // namespace nci
#endif  /* __VIRTUALFRAME_HEADER_FILE_H */
