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

	int low = ' ';	/* Space = 32 */
	int high = '~';	/* Tilde = 126 */

	for(int i = low; i <= high; i++)
	{
		std::cout << static_cast<char>(i) << "\t\t= " << i << ","
		<< "\t/* " << static_cast<char>(i) << " */" << std::endl;
	}

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
		std::cout << "Check the log to see keys" << std::endl;

	std::cout << "End of execution" << std::endl;
	return 0;
}
