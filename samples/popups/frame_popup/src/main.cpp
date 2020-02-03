#include <iostream>

#include "nci.h"
#include "imanager.h"
#include "frame.h"

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

	nci::Point2D origin_1(0, 0);
	nci::Size2D size_1(screen_size.width, screen_size.height);
	std::shared_ptr<nci::Frame> frame_1(new nci::Frame("Frame_1", origin_1, size_1));
	frame_1->set_background_color(3);
	frame_1->set_border(true);	/* true by default */
	frame_1->generate_help_pop_from_keybinding();

	manager.add(frame_1);
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
	/* Create a thread to change data after a while */
	// TODO

	if (!result)
		std::cout << "Could not run manager" << std::endl;

	std::cout << "End of execution" << std::endl;
	return 0;
}
