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

class Frame : public VirtualFrame
{
public:
    Frame(std::string id, Point2D origin = Point2D(0, 0), Size2D size = Size2D(1, 1));
    ~Frame();

    void draw();
    void run();

    void set_background_color(int color_id);
};

}   // namespace nci
#endif  /* __FRAME_HEADER_FILE_H */
