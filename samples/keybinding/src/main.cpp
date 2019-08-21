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

	/* Create a standalone text label */
	nci::Point2D origin_text_0(1, 1);
	nci::Size2D size_text_0(20, 20);
	std::shared_ptr<nci::TextFrame> textframe_0(new nci::TextFrame("TextFrame_0", origin_text_0, size_text_0));
	textframe_0->set_text("Hello Keybinding!!! This tutorial print key pushed using keybindingcontainer");

	nci::Point2D origin_text_1(1, 22);
	nci::Size2D size_text_1(20, 20);
	std::shared_ptr<nci::TextFrame> textframe_1(new nci::TextFrame("TextFrame_1", origin_text_1, size_text_1));
	textframe_1->set_text("");
	textframe_1->set_background_color(2);

	manager.add(textframe_0);
	manager.add(textframe_1);
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
