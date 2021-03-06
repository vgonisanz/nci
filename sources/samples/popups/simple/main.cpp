#include <iostream>

#include "nci.h"
#include "imanager.h"
#include "popup.h"

/**
 * Create a frame that use whole screen
 */
bool run_frontend()
{
	/* First create manager to initialize ncurse, handle stdout and windows */
	nci::IManager manager;

	/* Create a standalone popup */
	nci::Size2D screen_size2 = nci::IManager::get_size();
	std::cout << "screen_size2: " << screen_size2.width << ", " << screen_size2.height << std::endl;

	std::shared_ptr<nci::Popup> popup_0(new nci::Popup("Popup_0"));
	popup_0->set_background_color(2);
	popup_0->set_title("Informative popup");
	popup_0->set_text("Hello world popup in da jaus!");
	//popup_0->get_border_size();
	popup_0->run();
	//anager.launch(popup_0);

	return true;
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
	/* Create a thread to change data after a while */
	// TODO

	if (!result)
		std::cout << "Could not run manager" << std::endl;

	std::cout << "End of execution" << std::endl;
	return 0;
}
