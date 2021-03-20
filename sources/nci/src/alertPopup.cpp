#include "alertPopup.h"

#include <ncurses.h>
#include <sstream>

#include "imanager.h"
#include "utils.h"
#include "button.h"

namespace nci
{

AlertPopup::AlertPopup(std::string id, std::string text):
Popup(id, "PopUps")
{
    std::cout << "Create Popup: " << _id << std::endl;

    _size = IManager::get_size();
    create(Point2D(_size.width/4, _size.height/4), Size2D(_size.width/2, _size.height/2));
	create_btn_ok();
	create_btn_cancel();	
}

AlertPopup::~AlertPopup()
{
    std::cout << "Destroying Alert Popup: " << _id << std::endl;
    destroy();
}

void AlertPopup::create(Point2D origin, Size2D _size)
{
    move(origin);
    resize(_size);
}

void AlertPopup::destroy()
{
    delwin(_border);
}

void AlertPopup::create_btn_ok()
{
	nci::Point2D origin_btn_ok((_size.width/3), _size.height-(_size.height/3)-1);
	nci::Size2D size_btn_ok(13, 3);
	std::shared_ptr<nci::Button> button_ok(new nci::Button("Button OK", origin_btn_ok, size_btn_ok));
	_button_ok = button_ok;
	_button_ok->set_background_color(0);
	_button_ok->set_border(true);
	_button_ok->set_text("OK");
	_button_ok->set_runnable(true);
	add(_button_ok);
}

void AlertPopup::create_btn_cancel()
{
	nci::Point2D origin_btn_cancel(_size.width-(_size.width/2), _size.height-(_size.height/3)-1);
	nci::Size2D size_btn_cancel(13, 3);
	std::shared_ptr<nci::Button> button_cancel(new nci::Button("Button Cancel", origin_btn_cancel, size_btn_cancel));
	_button_cancel = button_cancel;
	_button_cancel->set_background_color(0);
	_button_cancel->set_border(true);
	_button_cancel->set_text("CANCEL");
	_button_cancel->set_runnable(true);

	add(_button_cancel);
}

void AlertPopup::set_pressed_btn_ok_callback(std::function<void()> function)
{
	_button_ok->set_button_callback(function);
}

void AlertPopup::set_pressed_btn_cancel_callback(std::function<void()> function)
{
	_button_cancel->set_button_callback(function);
}

void AlertPopup::set_modify_text_button_ok(std::string text)
{
	_button_ok->set_text(text);
}

void AlertPopup::set_modify_text_button_cancel(std::string text)
{
	_button_cancel->set_text(text);
}

} // namespace nci