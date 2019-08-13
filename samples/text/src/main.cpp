#include <iostream>

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

	/* Create a standalone text label */
	nci::Point2D origin_text_1(1, 1);
	nci::Size2D size_text_1(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_1(new nci::TextFrame("TextFrame_1", origin_text_1, size_text_1));
	textframe_1->set_text("Hello world!");

	nci::Point2D origin_1(screen_size.width/2, screen_size.height/2);
	nci::Size2D size_1(screen_size.width/2, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_1(new nci::Frame("Frame_1", origin_1, size_1));
	frame_1->set_background_color(3);

	/* Create a children text for red frame */
	nci::Point2D origin_text_2(1, 1);
	nci::Size2D size_text_2(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_2(new nci::TextFrame("TextFrame_2", origin_text_2, size_text_2));
	textframe_2->set_text("I'm a children");


	/* Create a editable text */
	// TODO

	manager.add(textframe_1);
	manager.add(frame_1);
	frame_1->add(textframe_2);
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
