#pragma once
#include "../Headers/Activity.h"
class Print : public Activity
{
private:
	Container* related_;
public:
	Print(Container* related);
	void run();
	void show_name() const;
};
Print::Print(Container* related) : related_(related) {}
void Print::run()
{
	std::cout << std::endl;
	std::cout << "[ The Telephone Directory Is : ]\n";
	std::sort(related_->persons().begin(), related_->persons().end(), [](Person& p1, Person& p2) { return p1.name() < p2.name(); });
	std::for_each(related_->persons().begin(), related_->persons().end(), [](Person& p) { p.print(); });
	std::cout << std::endl;
}
void Print::show_name() const
{
	std::cout << "[ Print ]\n";
}