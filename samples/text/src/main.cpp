#include <iostream>

#include "imanager.h"
#include "frame.h"

/**
 * Create a frame that use whole screen
 */
bool run_frontend()
{
	/* First create manager to initialize ncurse, handle stdout and windows */
	nci::IManager manager;
	nci::Size2D screen_size = manager.get_size();

	nci::Point2D origin_1(0, 0);
	nci::Size2D size_1(screen_size.width, screen_size.height);
	std::shared_ptr<nci::Frame> frame_1(new nci::Frame("Frame_1", origin_1, size_1));
	frame_1->set_background_color(3);

	/* Create a text label */
	// TODO
	/* Create a editable text */
	// TODO

	manager.add_frame(std::shared_ptr<nci::Frame>(frame_1));
	return manager.run();
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
