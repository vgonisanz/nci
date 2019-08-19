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
//#include "imanager.h"

namespace nci
{

class Popup : public Frame
{
protected:
    std::string _title;
    std::string _text;

    WINDOW *_title_win;
    WINDOW *_text_win;

public:
    Popup(std::string id, std::string text = "");
    ~Popup();

    void draw();
    void run();

    void resize(Size2D size);

    void set_screen_size(Size2D size) { resize(size); };
    void set_title(std::string text);
    void set_text(std::string text);

    void set_background_color(int color_id);
};

}   // namespace nci
#endif  /* __POPUP_HEADER_FILE_H */
