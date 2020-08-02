#pragma once
#include "../Headers/Activity.h"
#include "../SourceFiles/Person.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <string>
class Container : public Activity // ���绰������Ŀ�Ļ
{
protected:
	std::string file_directory_; //�ļ���ַ
	std::vector<Person> persons_; // ����
public:
	Container(std::string file_directory) : file_directory_(file_directory) //���캯��
	{}
	void show_name() const;
	void run();
	std::vector<Person>& persons();
	~Container() {}
public:
	std::string directory();
};

std::vector<Person>& Container::persons()
{
	return persons_;
}
void Container::show_name() const// ��ӡRead Activity ������
{
	std::cout << "[ Read File ]\n";
}

void Container::run()
{
	std::ifstream infile(file_directory_);
	if (!(infile.good())) // ���ifstream״̬����
	{
		throw "ifstream feels bad"; // �׳�һ���쳣
	}
	/*
	ÿ��ȡһ�У��Ž�һ��temp string� Ȼ��temp string ���ո�ָ����vector v�
	��v������Person������persons_��
	*/
	std::string temp_string, split_by_spaces;
	std::vector<std::string> v;

	while (std::getline(infile, temp_string))
	{
		std::stringstream ss(temp_string);
		while (ss >> split_by_spaces)
		{
			v.push_back(split_by_spaces);
		}
		persons_.push_back(Person(v));
		v.clear();
	}
	infile.close();
}

std::string Container::directory()
{
	return file_directory_;
}



void del(std::vector<Person>& v, std::vector<Person>::iterator i)
{
	v.erase(i);
}

class Modify : public Activity
{
private:
	Container* related_;
public:
	Modify(Container* related);
	void run();
	void show_name() const;
};
Modify::Modify(Container* related) : related_(related) {}
void Modify::run()
{
	std::string command;
	std::cout << ">>> ";
	std::getline(std::cin, command);
	std::vector<std::string> splited_command;
	std::stringstream ss(command);
	std::string temp;
	while (ss >> temp)
	{
		splited_command.push_back(temp);
	}
	if (splited_command[0] == "name") // if is name
	{
		auto res = std::find_if(related_->persons().begin(), related_->persons().end(),
			[&splited_command](Person& p)
			{
				return p.name() == splited_command[1];
			});
		if (res == related_->persons().end())
		{
			std::cout << "\n[ Not Found Name Called " + splited_command[1] << " ]" << std::endl;
			goto BAD_END;
		}
		else
		{
			if (splited_command[2] == "del")
			{
				del(related_->persons(), res);
				goto GOOD_END;
			}
			if(splited_command[2] == "to")
			{
				res->name() = splited_command[3];
				goto GOOD_END;
			}
		}
	}
	else if (splited_command[0] == "phone") // if is phone number
	{
		auto res = std::find_if(related_->persons().begin(), related_->persons().end(),
			[&splited_command](Person& p) -> bool
			{
				return p.phone_number() == splited_command[1];
			});
		if (res == related_->persons().end())
		{
			std::cout << "\n[ Not Found Phone Number Called " + splited_command[1] << " ]" << std::endl;
			goto BAD_END;
		}
		else
		{
			if (splited_command[2] == "del")
			{
				del(related_->persons(), res);
				goto GOOD_END;
			}
			if (splited_command[2] == "to")
			{
				res->phone_number() = splited_command[3];
				goto GOOD_END;
			}
		}
	}
	else
	{
		std::cout << "[ Invalid Input :( ]" << std::endl;
		goto BAD_END;
	}
GOOD_END: std::cout << "\n[ Modify done! ]\n";
BAD_END: return;
}
void Modify::show_name() const
{
	std::cout << "[ Modify ]\n";
}



class Add : public Activity
{
private:
	Container* related_;
public:
	Add(Container* related);
	void run();
	void show_name() const;
};
Add::Add(Container* related) : related_(related) {}

void Add::run()
{
	std::string s;
	std::getline(std::cin, s);
	std::vector<std::string> v;
	std::stringstream ss(s);
	while (ss >> s)
	{
		v.push_back(s);
	}
	related_->persons().push_back(Person(v));
}

void Add::show_name() const
{
	std::cout << "[ Add An Item ]\n";
}