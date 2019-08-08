#include <iostream>

#include "imanager.h"
#include "frame.h"

bool run_frontend()
{
	auto frame = std::make_shared<nci::Frame>();
	nci::IManager manager;
	manager.init();
	manager.add_frame(frame);
	return manager.run();
}

int main()
{
	bool result = run_frontend();

	if (!result)
		std::cout << "Could not run manager" << std::endl;

	std::cout << "End of execution" << std::endl;
	return 0;
}
