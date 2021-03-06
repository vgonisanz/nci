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
	frame_0->set_background_color(6);
	frame_0->set_runnable(true);
	frame_0->generate_help_pop_from_keybinding();

	/* Create a standalone text label */
	nci::Point2D origin_text_0(0, 0);
	nci::Size2D size_text_0(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_0(new nci::TextFrame("TextFrame_0", origin_text_0, size_text_0));
	textframe_0->set_text("Hello world!");

	/* Red frame with text */
	nci::Point2D origin_1(screen_size.width/2, 0);
	nci::Size2D size_1(screen_size.width/2, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_1(new nci::Frame("Frame_1", origin_1, size_1));
	frame_1->set_background_color(3);
	frame_1->set_runnable(true);
	frame_1->generate_help_pop_from_keybinding();
	

	/* Create a children text for red frame */
	nci::Point2D origin_text_1(0, 0);
	nci::Size2D size_text_1(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_1(new nci::TextFrame("TextFrame_1", origin_text_1, size_text_1));
	textframe_1->set_text("I'm children YOOOOOOOO");
	textframe_1->set_background_color(3);

	/* Blue frame with text */
	nci::Point2D origin_2(0, screen_size.height/2);
	nci::Size2D size_2(screen_size.width/2, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_2(new nci::Frame("Frame_2", origin_2, size_2));
	frame_2->set_background_color(4);
	frame_2->set_runnable(true);
	frame_2->generate_help_pop_from_keybinding();

	/* Create a children text for blue frame */
	nci::Point2D origin_text_2(0, 0);
	nci::Size2D size_text_2(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_2(new nci::TextFrame("TextFrame_2", origin_text_2, size_text_2));
	textframe_2->set_text("I'm children 2");

	/* Green frame with text */
	nci::Point2D origin_3(screen_size.width/2, screen_size.height/2);
	nci::Size2D size_3(screen_size.width/2, screen_size.height/2);
	std::shared_ptr<nci::Frame> frame_3(new nci::Frame("Frame_3", origin_3, size_3));
	frame_3->set_background_color(5);
	frame_3->set_runnable(true);
	frame_3->generate_help_pop_from_keybinding();

	/* Create a children text for green frame */
	nci::Point2D origin_text_3(0, 0);
	nci::Size2D size_text_3(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_3(new nci::TextFrame("TextFrame_3", origin_text_3, size_text_3));
	textframe_3->set_text("I'm children 3");

	manager.add(frame_0);
	
	manager.add(frame_1);
	manager.add(frame_2);
	manager.add(frame_3);
	frame_0->add(textframe_0);
	frame_1->add(textframe_1);
	frame_2->add(textframe_2);
	frame_3->add(textframe_3);
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
