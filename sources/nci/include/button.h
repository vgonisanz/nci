/**
 * @file            frame.h
 * @version         1.0
 * @date            March 2021
 * @brief           Main nci workspace.
 * @author          vgonisanz/ntamurejo
 *
 * Pure virtual Frame base class
 *
 * @license LGPL v3.0
 */
#ifndef __BUTTON_HEADER_FILE_H
#define __BUTTON_HEADER_FILE_H

#include <ncurses.h>
#include <iostream>

#include "types.h"
#include "frame.h"
#include "textFrame.h"

namespace nci
{

class Button : public Frame
{
    private:
        void  button_pressed();

    protected:
        TextFrame _text_frame;
        std::function<void()> _button_callback;

    public:
        Button(std::string id, Point2D origin = Point2D(0, 0), Size2D size = Size2D(1, 1));
        ~Button();

        void draw();
        void run();
        void invert_draw(unsigned int animation_delay_in_us = 100000);

        void set_text(std::string text);
        std::string get_text();

        virtual bool get_selected() const;
        virtual void set_selected(bool highlight);
        virtual void border_selected();
        virtual void set_button_callback(std::function<void()> function);
        void blink();
};

}   // namespace nci
#endif  /* __BUTTON_HEADER_FILE_H */
