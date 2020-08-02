#pragma once
#include "../Headers/Activity.h"
#include <iostream>
class Save : public Activity
{
protected:
	// ����һ��Load Activityָ�룬 ���������(related to)����Load Activity�Ķ����ϣ�
	//ʹ����ͬ������Load Activity���º��persons����
	Container* related_;
public:
	Save(Container* related);
	void run();
	void show_name() const;
};
Save::Save(Container* related) : related_(related) {}
void Save::run()
{
	//std::string command;
	//std::getline(std::cin, command);
	//modify(command);
	std::ofstream outfile(related_->directory()); //���ļ�
	if (!outfile.good())
	{
		throw "outfile error"; //�׳�һ���쳣
	}
	auto temp = related_->persons();
	std::for_each(temp.begin(),
		temp.end(),
		[&outfile](Person& p)
		{
			outfile << p.item(); 
		});
	outfile.close();
	std::cout << "[ Saved! ]" << std::endl;
}

void Save::show_name() const
{
	std::cout << "[ Save ]\n";
}