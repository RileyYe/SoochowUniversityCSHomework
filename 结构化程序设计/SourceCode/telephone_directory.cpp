#include <iostream>
#include <string>
#include <cctype>
#include <array>
#include <iomanip>
#include "Activity/SourceFiles/Manage.cpp"
#include "Activity/SourceFiles/BackUp.cpp"
#include "Activity/SourceFiles/Print.cpp"
#include "Activity/SourceFiles/Save.cpp"
#include "Activity/SourceFiles/Query.cpp"
#include "Activity/SourceFiles/Exit.cpp"
int main()
{
	Container c("./sample.txt");
	c.run(); // 加载数据
	Print print(&c); //打印
	Save sv(&c); //保存
	Add add(&c); //添加
	Modify mdf(&c); //修改
	BackUp backup(&c); //备份
	Query q(&c); // 查询
	Exit ext = Exit(); // 退出
	std::array<Activity*, 7> main_menu = { &print, &mdf, &add, &q, &sv,  &backup, &ext};
	std::cout << std::setw(10) << "[ IMPORTANT ]\n" << "The Modify Module Is Command-Based, Check README To Know How To Use.\n\n";
	while (true)
	{
		int index = 1;
		std::for_each(main_menu.begin(), main_menu.end(), [&index](Activity* a) { std::cout << index++ << ". "; a->show_name(); });
		std::cout << std::endl
			<< ">>> ";
		std::cin >> index;
		switch (index)
		{
		case 1:
			main_menu[0]->run(); // 打印
			break;
		case 2:
			std::cin.ignore();
			main_menu[1]->run(); // 修改
			std::cout << std::endl;
			main_menu[0]->run(); // 打印修改后的结果
			break;
		case 3:
			std::cin.ignore();
			main_menu[2]->run(); //添加
			std::cout << std::endl;
			break;
		case 4:
			main_menu[3]->run(); //查询
			std::cout << std::endl;
			break;
		case 5:
			main_menu[5]->run();//备份
			main_menu[4]->run(); //保存
			std::cout << std::endl;
			break;
		case 6:
			main_menu[5]->run(); //备份
			std::cout << std::endl;
			break;
		case 7:
			main_menu[5]->run(); //保存前备份
			main_menu[4]->run(); // 退出前保存
			main_menu[6]->run();
			break;
		default:
			break;
		}
	}
}