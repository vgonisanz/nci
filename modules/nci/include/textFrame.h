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
#ifndef __TESTFRAME_HEADER_FILE_H
#define __TESTFRAME_HEADER_FILE_H

#include <ncurses.h>
#include <iostream>

#include "types.h"
#include "frame.h"

namespace nci
{

class TextFrame : public Frame
{
protected:
    std::string _text;

public:
    TextFrame(std::string id, Point2D origin = Point2D(0, 0), Size2D size = Size2D(1, 1));
    ~TextFrame();

    void draw();
    void run();

    void set_text(std::string text);
    std::string get_text();
};

}   // namespace nci
#endif  /* __TESTFRAME_HEADER_FILE_H */
