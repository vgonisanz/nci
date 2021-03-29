#include <iostream>

#include "nci.h"
#include "imanager.h"
#include "textFrame.h"
#include "frame.h"

/**
 * Create a frame that use whole screen
 */
bool run_frontend()
{
	/* First create manager to initialize ncurse, handle stdout and windows */
	nci::IManager manager;
	nci::Size2D screen_size = manager.get_size();

	/* Black frame with text */
	nci::Point2D origin_0(0,0);
	nci::Size2D size_0(screen_size.width/2, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_0(new nci::Frame("Frame_0", origin_0, size_0));
	frame_0->set_background_color(5);
	frame_0->set_border(true);
	
	/* Create a standalone text label */
	nci::Point2D origin_text_0(0.01*(screen_size.width/2), 0.01*(screen_size.width/2));
	nci::Size2D size_text_0(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_0(new nci::TextFrame("TextFrame_0", origin_text_0, size_text_0));
	textframe_0->set_text("Hello world!");

	/* Red frame with text */
	nci::Point2D origin_1(screen_size.width/2, 0);
	nci::Size2D size_1(screen_size.width/2, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_1(new nci::Frame("Frame_1", origin_1, size_1));
	frame_1->set_background_color(3);
	frame_1->set_border(true);

	nci::Point2D origin_text_1(screen_size.width/2 + 0.01*(screen_size.width/2), 0.01*(screen_size.width/2));
	nci::Size2D size_text_1(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_1(new nci::TextFrame("TextFrame_1", origin_text_1, size_text_1));
	textframe_1->set_text("I'm children");


	manager.add(frame_0);
	manager.add(frame_1);

	manager.add(textframe_0);
	manager.add(textframe_1);

	return manager.run();
}

int main()
{
	bool result = false;
	std::cout << "Point 1" << std::endl;
 	try
	{
		std::cout << "Point 2" << std::endl;
		result = run_frontend();
	}
	catch (const std::exception& e)
	{
		std::cout << "Point 3" << std::endl;
		nci::tear_down_ncurses();
	}
	std::cout << "Point 4" << std::endl;
	if (!result)
		std::cout << "Could not run manager" << std::endl;
	std::cout << "End of execution" << std::endl;
	return 0;
}
