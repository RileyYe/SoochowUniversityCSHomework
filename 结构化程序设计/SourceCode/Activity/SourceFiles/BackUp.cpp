#pragma once
#include "../Headers/Activity.h"
#include <ctime>
class BackUp : public Activity // Back_Up Activity, �� Load_Activityʵ����������ݱ��ݣ� ��ֹ�������޸ĵĲ�����
{
private:
	Container* related_;
public:
	BackUp(Container* related);
	void run();
	void show_name() const;
};

BackUp::BackUp(Container* related) : related_(related) {}
void BackUp::run()
{
	std::time_t current_time;
	std::ofstream outfile("./Backup/" + std::to_string(std::time(&current_time)) + ".bak");
	if (!outfile.good())
	{
		throw "ofstream feels bad";
	}
	std::for_each(related_->persons().begin(), related_->persons().end(),
		[&outfile](Person& p)
		{
			outfile << p.item();
		});
	std::cout << "\n[ Backup done! ]\n";
}
void BackUp::show_name() const
{
	std::cout << "[ Backup ]\n";
}