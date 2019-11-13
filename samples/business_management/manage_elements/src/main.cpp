#include <iostream>

#include "nci.h"
#include "imanager.h"
#include "textFrame.h"
#include "frame.h"

void print_output(std::shared_ptr<nci::TextFrame> text, std::string name, std::string description)
{
	std::cout << "print_output, name: " << name << " description: " << description << std::endl;

	text->set_text("Name: " + name + " is: " + description);
	text->draw();
}

/**
 * Create a frame that use whole screen
 */
bool run_frontend()
{
	/* First create manager to initialize ncurse, handle stdout and windows */
	nci::IManager manager;
	nci::Size2D screen_size = manager.get_size();

	/* Input */
	nci::Point2D origin_frame_input(screen_size.width/4, screen_size.height/4);
	nci::Size2D size_frame_input(screen_size.width/2, screen_size.height/4);
	std::shared_ptr<nci::Frame> frame_input(new nci::Frame("Frame_input", origin_frame_input, size_frame_input));
	frame_input->set_background_color(4);
	frame_input->set_runnable(true);

	nci::Point2D origin_text_name(0, 0);
	nci::Size2D size_text_name(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_name(new nci::TextFrame("TextFrame_name", origin_text_name, size_text_name));
	textframe_name->set_text("Name:");
	textframe_name->set_background_color(4);

	nci::Point2D origin_text_input_name(0, 1);
	nci::Size2D size_text_input_name(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_input_name(new nci::TextFrame("TextFrame_input_name", origin_text_input_name, size_text_input_name));
	textframe_input_name->set_text("<name>");
	textframe_input_name->set_background_color(4);
	textframe_input_name->set_editable(true);

	nci::Point2D origin_text_description(0, 4);
	nci::Size2D size_text_description(20, 1);
	std::shared_ptr<nci::TextFrame> textframe_description(new nci::TextFrame("TextFrame_description", origin_text_description, size_text_description));
	textframe_description->set_text("Description:");
	textframe_description->set_background_color(4);

	nci::Point2D origin_text_input_description(0, 5);
	nci::Size2D size_text_input_description(20, 4);
	std::shared_ptr<nci::TextFrame> textframe_input_description(new nci::TextFrame("TextFrame_input_description", origin_text_input_description, size_text_input_description));
	textframe_input_description->set_text("<description>");
	textframe_input_description->set_background_color(4);
	textframe_input_description->set_editable(true);

	/* Output */
	nci::Point2D origin_text_output(0, 0);
	nci::Size2D size_text_output(20, 4);
	std::shared_ptr<nci::TextFrame> textframe_output(new nci::TextFrame("TextFrame_output", origin_text_output, size_text_output));
	textframe_output->set_text("<output>");
	textframe_output->set_background_color(3);
	textframe_output->set_runnable(false);

	nci::Point2D origin_frame_output(screen_size.width/4, screen_size.height/2);
	nci::Size2D size_frame_output(screen_size.width/2, screen_size.height/4);
	std::shared_ptr<nci::Frame> frame_output(new nci::Frame("Frame_output", origin_frame_output, size_frame_output));
	frame_output->set_background_color(3);
	frame_output->set_runnable(false);

	//print_output

	/* Set up UI hierarchy */
	frame_input->add(textframe_name);
	frame_input->add(textframe_input_name);
	frame_input->add(textframe_description);
	frame_input->add(textframe_input_description);
	frame_output->add(textframe_output);
	manager.add(frame_input);
	manager.add(frame_output);
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

	/* Create a thread to change data after a while */
	// TODO

	if (!result)
		std::cout << "Could not run manager" << std::endl;

	std::cout << "End of execution" << std::endl;
	return 0;
}
