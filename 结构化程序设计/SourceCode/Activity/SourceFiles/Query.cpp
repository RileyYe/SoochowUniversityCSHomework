#pragma once
#include "../Headers/Activity.h"
#include "Manage.cpp"
class Query : public Activity
{
public:
	Container* related_;
public:
	Query(Container* related) : related_(related) {}
	void run();
	void show_name() const;
	void name_query() const;
	void phone_query() const;
	void address_query() const;
	void type_query() const;
};

void Query::show_name() const
{
	std::cout << "[ Query/... ]" << std::endl;
}
void Query::run()
{
	int num = 0;
	while (true)
	{
		std::cout << "\n1. [ Query By Name ]" << std::endl
			<< "2. [ Query By Phone Number ]" << std::endl
			<< "3. [ Query By Address (Fuzzy Lookup) ]" << std::endl
			<< "4. [ Query By Type ]"  << std::endl
			<< "5. [ Back To Parent Menu ]\n" << std::endl
			<< std::endl;
		std::cout << ">>> ";
		std::cin >> num;
		switch (num)
		{
		case 1:
			name_query();
			break;
		case 2:
			phone_query();
			break;
		case 3:
			address_query();
			break;
		case 4:
			type_query();
			break;
		case 5:
			return;
		default:
			break;
		}
	}
}
void Query::name_query() const
{
	std::string name;
	std::cout << "The Name Is :\n >>> ";
	std::cin >> name;
	std::cout << "\nFound : \n";
	for (auto i = related_->persons().begin(); i != related_->persons().end(); ++i)
	{
		if (i->name() == name)
		{
			std::cout << i->item();
		}
	}
}
void Query::phone_query() const
{
	std::string phone;
	std::cin >> phone;
	std::cout << "\nFound : \n";
	for (auto i = related_->persons().begin(); i != related_->persons().end(); ++i)
	{
		if (i->phone_number() == phone)
		{
			std::cout << i->item();
		}
	}
}
void Query::address_query() const
{
	std::string address;
	std::cin >> address;
	std::cout << "\nFound : \n";
	for (auto i = related_->persons().begin(); i != related_->persons().end(); ++i)
	{
		auto pos = i->address().find(address);
		if ( pos != i->address().npos)
		{
			std::cout << i->item();
		}
	}
}
void Query::type_query() const
{
	std::string type;
	std::cin >> type;
	std::cout << "\nFound : \n";
	for (auto i = related_->persons().begin(); i != related_->persons().end(); ++i)
	{
		if (i->type() == type)
		{
			std::cout << i->item();
		}
	}
}