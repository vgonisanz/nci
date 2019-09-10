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

	/* TOP-LEFT frames with box - Inside frame is smaller than parent frame */
	// nci::Point2D origin_top_left(0, 0);
	// nci::Size2D size_top_left(screen_size.width/2, screen_size.height/2);
	// std::shared_ptr<nci::Frame> frame_top_left(new nci::Frame("frame_top_left", origin_top_left, size_top_left));
	// frame_top_left->set_background_color(3);
	//
	// nci::Point2D origin_top_left_in(0, 0);
	// nci::Size2D size_top_left_in(size_top_left.width - 2, size_top_left.height - 2);
	// std::shared_ptr<nci::Frame> frame_top_left_in(new nci::Frame("frame_top_left_in", origin_top_left_in, size_top_left_in));
	// frame_top_left_in->set_background_color(3);

	/* TOP-RIGHT frames without box - Inside frame is smaller than parent frame */
	nci::Point2D origin_top_right(screen_size.width/2, 0);
	nci::Size2D size_top_right(screen_size.width/4, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_top_right(new nci::Frame("Frame_top_right", origin_top_right, size_top_right));
	frame_top_right->set_background_color(4);
	//frame_top_right->set_border(false);

	// nci::Point2D origin_top_right_in(0, 0);
	// nci::Size2D size_top_right_in(size_top_left - 1);
	// std::shared_ptr<nci::Frame> frame_top_right_in(new nci::Frame("frame_top_right_in", origin_top_right_in, size_top_right_in));
	// frame_top_right_in->set_background_color(3);
	// frame_top_right_in->set_border(false);

	/* BOT-LEFT frames with box - Inside frame has same size than parent frame */
	// nci::Point2D origin_bot_left(0, size_top_left.height);
	// nci::Size2D size_bot_left(screen_size.width/2, screen_size.height/2);
	// std::shared_ptr<nci::Frame> frame_bot_left(new nci::Frame("frame_bot_left", origin_bot_left, size_bot_left));
	// frame_bot_left->set_background_color(5);
	//
	// nci::Point2D origin_bot_left_in(0, 0);
	// nci::Size2D size_bot_left_in(size_bot_left.width - 2, size_bot_left.height - 2);
	// std::shared_ptr<nci::Frame> frame_bot_left_in(new nci::Frame("frame_bot_left_in", origin_bot_left_in, size_bot_left_in));
	// frame_bot_left_in->set_background_color(5);
	//
	// /* BOT-RIGHT frames without box - Inside frame has same size than parent frame */
	// nci::Point2D origin_bot_right(size_bot_left.width, size_top_left.height);
	// nci::Size2D size_bot_right(size_bot_left);
	// std::shared_ptr<nci::Frame> frame_bot_right(new nci::Frame("frame_bot_right", origin_bot_right, size_bot_right));
	// frame_bot_right->set_background_color(6);
	// frame_bot_right->set_border(false);
	//
	// nci::Point2D origin_bot_right_in(0, 0);
	// nci::Size2D size_bot_right_in(size_bot_left - 1);
	// std::shared_ptr<nci::Frame> frame_bot_right_in(new nci::Frame("frame_bot_right_in", origin_bot_right_in, size_bot_right_in));
	// frame_bot_right_in->set_background_color(2);
	// frame_bot_right_in->set_border(false);

	// manager.add(frame_top_left);
	// frame_top_left->add(frame_top_left_in);

	manager.add(frame_top_right);
	//frame_top_right->add(frame_top_right_in);

	// manager.add(frame_bot_left);
	// frame_bot_left->add(frame_bot_left_in);
	//
	// manager.add(frame_bot_right);
	// frame_bot_right->add(frame_bot_right_in);

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
