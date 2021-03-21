/**
 * @file            popup.h
 * @version         1.0
 * @date            March 2021
 * @brief           Main nci workspace.
 * @author          ntamurejocolorado
 *
 * Pure virtual Frame base class
 *
 * @license LGPL v3.0
 */
#ifndef __ALERTPOPUP_HEADER_FILE_H
#define __ALERTPOPUP_HEADER_FILE_H

#include <ncurses.h>
#include <iostream>

#include "types.h"
#include "popup.h"
#include "button.h"
//#include "imanager.h"

namespace nci
{

class AlertPopup : public Popup
{

private:
    Size2D _size;

protected:
    std::string _title;
    std::string _text;

    WINDOW *_title_window;
    WINDOW *_text_window;

    std::shared_ptr<nci::Button> _button_ok;
    std::shared_ptr<nci::Button> _button_cancel;

public:
    AlertPopup(std::string id, std::string text = "");
    ~AlertPopup();

    void create(Point2D origin, Size2D size);
    void destroy();

    void create_btn_ok();
    void create_btn_cancel();

    void set_pressed_btn_ok_callback(std::function<void()> function);
    void set_pressed_btn_cancel_callback(std::function<void()> function);
    void set_modify_text_button_ok(std::string text);
    void set_modify_text_button_cancel(std::string text);

    void callback_ok();
    void callback_cancel();
};

}   // namespace nci
#endif  /* __POPUP_HEADER_FILE_H */
