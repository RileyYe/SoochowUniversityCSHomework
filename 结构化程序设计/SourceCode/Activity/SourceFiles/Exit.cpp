#pragma once
#include "../Headers/Activity.h"
#include <cstdlib>
class Exit : public Activity
{
public:
	Exit() {}
	void run() { std::cout << "[ Exited£¡ ]\n"; exit(0); }
	void show_name() const
	{
		std::cout << "[ Exit ]\n";
	}
};