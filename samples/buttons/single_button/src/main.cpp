#include <iostream>

#include "nci.h"
#include "imanager.h"
#include "textFrame.h"
#include "frame.h"
#include "button.h"


void foo()
{
	std::cout << "Funcion foo pulsada" << std::endl;
	
}

void var()
{
	std::cout << "Funcion var pulsada" << std::endl;
	
}

/**
 * Create a frame that use whole screen
 */
bool run_frontend()
{
	//Colors

	/* First create manager to initialize ncurse, handle stdout and windows */
	nci::IManager manager;
	nci::Size2D screen_size = manager.get_size();

	/* Black frame with text */
	nci::Point2D origin_0(0,0);
	nci::Size2D size_0(screen_size.width, screen_size.height);
	std::shared_ptr<nci::Frame> frame_0(new nci::Frame("Frame_0", origin_0, size_0));
	frame_0->set_background_color(7);
	frame_0->set_border(true);
	frame_0->set_runnable(true);
	

	/* Button 1 */
	nci::Point2D origin_btn_ok(screen_size.width/2, screen_size.height/3);
	nci::Size2D size_btn_ok(10, 3);
	std::shared_ptr<nci::Button> button_ok(new nci::Button("Button 1", origin_btn_ok, size_btn_ok));
	button_ok->set_background_color(0);
	button_ok->set_border(true);
	button_ok->set_text("Button 1");
	button_ok->set_runnable(true);
	button_ok->set_pressed_ok_callback(var);
	button_ok->generate_help_pop_from_keybinding();

	/* Button 2 */
	nci::Point2D origin_btn_2(screen_size.width/2, screen_size.height/2);
	nci::Size2D size_btn_2(10, 3);
	std::shared_ptr<nci::Button> button_2(new nci::Button("Button 2", origin_btn_2, size_btn_2));
	button_2->set_background_color(0);
	button_2->set_border(true);
	button_2->set_text("Button 2");
	button_2->set_runnable(true);
	button_2->set_pressed_ok_callback(foo);
	

	manager.add(frame_0);
	frame_0->add(button_ok);
	frame_0->add(button_2);
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
