#include <iostream>

#include "nci.h"
#include "imanager.h"
#include "frame.h"

/**
 * Create a 2 frames with children:
 *	- First: Child is smaller, do you see 2 concentric boxes?
 * 	- Second: Child is bigger, do you see 2 concentric boxes? size is fixed to
 *			  avoid overlapping.
 *
 * Both shall display in all cases
 */
bool run_frontend()
{
	/* First create manager to initialize ncurse, handle stdout and windows */
	nci::IManager manager;
	nci::Size2D screen_size = manager.get_size();

	nci::Point2D origin_1(0, 0);
	nci::Size2D size_1(screen_size.width, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_1(new nci::Frame("frame_1", origin_1, size_1));
	frame_1->set_background_color(3);

	nci::Point2D origin_1_1(0, 0);
	nci::Size2D size_1_1(screen_size.width - 2, screen_size.height/2 - 2);
	std::shared_ptr<nci::Frame> frame_1_1(new nci::Frame("frame_1_1", origin_1_1, size_1_1));
	frame_1_1->set_background_color(3);

	nci::Point2D origin_2(0, screen_size.height/2);
	nci::Size2D size_2(screen_size.width, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_2(new nci::Frame("Frame_2", origin_2, size_2));
	frame_2->set_background_color(4);

	nci::Point2D origin_2_1(0, 0);
	nci::Size2D size_2_1(screen_size.width, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_2_1(new nci::Frame("frame_2_1", origin_2_1, size_2_1));
	frame_2_1->set_background_color(4);

	manager.add(frame_1);
	manager.add(frame_2);
	frame_1->add(frame_1_1);
	frame_2->add(frame_2_1);
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
