#include <iostream>

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
	std::shared_ptr<nci::Popup> popup_0(new nci::Popup("Popup_0"));
	popup_0->set_text("Hello world popup!");
	manager.launch(popup_0);

	return true;
}

int main()
{
	bool result = run_frontend();

	/* Create a thread to change data after a while */
	// TODO

	if (!result)
		std::cout << "Could not run manager" << std::endl;

	std::cout << "End of execution" << std::endl;
	return 0;
}
