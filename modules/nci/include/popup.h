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

    WINDOW *_title_window;
    WINDOW *_text_window;

public:
    Popup(std::string id, std::string text = "");
    ~Popup();

    /**
     * \brief Create all windows follow internal variables
     *
     * Constructor use this method, but also setters that reconfigure the widget
     *
     */
    void create(Point2D origin, Size2D size);
    /**
     * \brief Destroy all windows follow internal variables
     *
     * Destructor use this method, but also setters that reconfigure the widget
     *
     */
    void destroy();
    /**
     * \brief Dummy method to draw the interface
     */
    void draw();
    /**
     * \brief Call internal logic to control the interface
     *
     * This method take the control until the execution end
     */
    void run();

    /**
     * \brief Resize the interface
     *
     * This method resize all internal windows active.
     */
    void resize(Size2D size);
    /**
     * \brief Text to show as title
     */
    void set_title(std::string text);
    /**
     * \brief Text to show as body
     */
    void set_text(std::string text);
    /**
     * \brief Put color on windows
     */
    void color_me();
    /**
     * \brief Draw a box around the border
     *
     * This method only draw if border window exist
     */
    void box_me();

};

}   // namespace nci
#endif  /* __POPUP_HEADER_FILE_H */
