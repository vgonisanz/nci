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

namespace nci
{

class Frame : protected VirtualFrame
{
protected:
    void create();
    void destroy();

public:
    Frame();
    ~Frame();

    void draw();
    void run();
};

}   // namespace nci
#endif  /* __FRAME_HEADER_FILE_H */
