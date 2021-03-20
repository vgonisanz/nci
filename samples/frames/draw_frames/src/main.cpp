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
	nci::Size2D screen_size = manager.get_size();
	std::cout << "screen_size: " << screen_size.width << ", " << screen_size.height << std::endl;

	nci::Point2D origin_1(0, 0);
	nci::Size2D size_1(screen_size.width/2, screen_size.height);
	std::shared_ptr<nci::Frame> frame_1(new nci::Frame("Frame_1", origin_1, size_1));
	frame_1->set_background_color(3);

	nci::Point2D origin_2(screen_size.width/2, 0);
	nci::Size2D size_2(screen_size.width/2, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_2(new nci::Frame("Frame_2", origin_2, size_2));
	frame_2->set_background_color(4);

	nci::Point2D origin_3(screen_size.width/2, screen_size.height/2);
	nci::Size2D size_3(screen_size.width/2, screen_size.height/2 + 1);
	std::shared_ptr<nci::Frame> frame_3(new nci::Frame("Frame_3", origin_3, size_3));
	frame_3->set_border(false);
	frame_3->set_background_color(5);
	frame_3->set_border(true);

	nci::Point2D origin_4(screen_size.width/4, screen_size.height/4);
	nci::Size2D size_4(screen_size.width/2, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_4(new nci::Frame("Frame_4", origin_4, size_4));
	frame_4->set_border(false);
	frame_4->set_background_color(6);

	manager.add(frame_1);
	manager.add(frame_2);
	manager.add(frame_3);
	manager.add(frame_4);
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
