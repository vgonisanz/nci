#include <iostream>

#include "nci.h"
#include "imanager.h"
#include "alertPopup.h"


void callback_ok()
{
	std::cout << "Button Ok pressed " << std::endl;
	
}

void callback_cancel()
{
	std::cout << "Button Cancel pressed " << std::endl;
	
}

/**
 * Create a frame that use whole screen
 */
bool run_frontend()
{
	/* First create manager to initialize ncurse, handle stdout and windows */
	nci::IManager manager;

	/* Create a standalone popup */
	nci::Size2D screen_size = nci::IManager::get_size();
	std::cout << "screen_size: " << screen_size.width << ", " << screen_size.height << std::endl;
	
	std::shared_ptr<nci::AlertPopup> popup_alert(new nci::AlertPopup("Popup-Quit"));
	popup_alert->set_background_color(8);
	popup_alert->set_title("Quit");
	popup_alert->set_text("Are you sure to quit?");
	popup_alert->set_runnable(true);
	popup_alert->set_pressed_btn_ok_callback(callback_ok);
	popup_alert->set_pressed_btn_cancel_callback(callback_cancel);
	popup_alert->set_modify_text_button_ok("Ok");
	popup_alert->set_modify_text_button_cancel("Cancel");

	manager.add(popup_alert);
	return manager.run();
}

int main()
{
	bool result = false;

 	try
	{
		result = run_frontend();
	}
	catch (const std::exception& e)
	{
		nci::tear_down_ncurses();
	}

	if (!result)
		std::cout << "Could not run manager" << std::endl;

	std::cout << "End of execution" << std::endl;
	return 0;
}
