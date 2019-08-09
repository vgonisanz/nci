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
	nci::Size2D size_1(screen_size.width/2, screen_size.height);
	std::shared_ptr<nci::Frame> frame_1(new nci::Frame("Frame_1", origin_1, size_1));
	frame_1->set_background_color(3);

	nci::Point2D origin_2(screen_size.width/2, 0);
	nci::Size2D size_2(screen_size.width/2, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_2(new nci::Frame("Frame_2", origin_2, size_2));
	frame_2->set_background_color(4);

	nci::Point2D origin_3(screen_size.width/2, screen_size.height/2);
	nci::Size2D size_3(screen_size.width/2, screen_size.height/2 + 1); /* Check how manage sizes */
	std::shared_ptr<nci::Frame> frame_3(new nci::Frame("Frame_3", origin_3, size_3));
	frame_3->set_background_color(5);

	manager.add_frame(std::shared_ptr<nci::Frame>(frame_1));
	manager.add_frame(std::shared_ptr<nci::Frame>(frame_2));
	manager.add_frame(std::shared_ptr<nci::Frame>(frame_3));
	return manager.run();
}

int main()
{
	bool result = run_frontend();

	if (!result)
		std::cout << "Could not run manager" << std::endl;

	std::cout << "End of execution" << std::endl;
	return 0;
}
