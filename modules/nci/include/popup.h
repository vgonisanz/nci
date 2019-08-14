/**
 * @file            popup.h
 * @version         1.0
 * @date            August 2019
 * @brief           Main nci workspace.
 * @author          vgonisanz
 *
 * Pure virtual Frame base class
 *
 * @license LGPL v3.0
 */
#ifndef __POPUP_HEADER_FILE_H
#define __POPUP_HEADER_FILE_H

#include <ncurses.h>
#include <iostream>

#include "types.h"
#include "frame.h"

namespace nci
{

class Popup : public Frame
{
public:
    Popup(std::string id, std::string text = "");
    ~Popup();

    void draw();
    void run();

    void set_text(std::string text);
    void set_screen_size(Size2D size) { resize(size); };
};

}   // namespace nci
#endif  /* __POPUP_HEADER_FILE_H */
