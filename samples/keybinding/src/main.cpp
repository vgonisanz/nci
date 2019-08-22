#include <iostream>

#include "imanager.h"
#include "textFrame.h"
#include "frame.h"

void print_key()
{
	std::cout << "print_key" <<  std::endl;
}

void print_key_int(std::shared_ptr<nci::TextFrame> text, int key)
{
	std::cout << " print_key_int " << key <<  std::endl;

	text->set_text("User pushed: " + std::to_string(key));
	text->draw();
}

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
	textframe_1->set_runnable(true);
	textframe_1->set_background_color(2);

	/* Binding
 	 *
	 * w --> Call print with int using value copy, if change -> print first assigned
	 * e --> Call print with int using value as reference, if change -> print change
	 * r --> Call print
	*/
	int value_int = 4;
	textframe_1->keybind('w', std::bind(print_key_int, textframe_1, value_int));
	textframe_1->keybind('e', std::bind(print_key_int, textframe_1, std::ref(value_int)));
	value_int = 5;	/* Change after assign by reference */
	textframe_1->keybind('r', print_key);

	manager.add(textframe_0);
	manager.add(textframe_1);
	return manager.run();
}

int main()
{
	bool result = run_frontend();
	//test();

	/* Create a thread to change data after a while */
	// TODO

	if (!result)
		std::cout << "Could not run manager" << std::endl;

	std::cout << "End of execution" << std::endl;
	return 0;
}
