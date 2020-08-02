#pragma once
#include "../Headers/Activity.h"
#include <iostream>
class Save : public Activity
{
protected:
	// 包含一个Load Activity指针， 让其关联到(related to)具体Load Activity的对象上，
	//使其能同步访问Load Activity更新后的persons内容
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
	std::ofstream outfile(related_->directory()); //打开文件
	if (!outfile.good())
	{
		throw "outfile error"; //抛出一个异常
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