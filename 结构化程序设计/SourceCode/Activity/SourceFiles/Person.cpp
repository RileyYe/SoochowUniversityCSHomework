#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Person
{
private:
    std::vector<std::string> data_;
public:
    Person(std::vector<std::string> data) :data_(data) {}
    std::string& name();
    std::string& gender();
    std::string& phone_number();
    std::string& address();
    std::string& address_code();
    std::string& email();
    std::string& qq_number();
    std::string& type();
    void print() const ;
    std::string item();
};
std::string& Person::name()
{
	return data_[0];
}
std::string& Person::address()
{
	return data_[3];
}
std::string& Person::address_code()
{
	return data_[4];
}
std::string& Person::email()
{
	return data_[5];
}
std::string& Person::gender()
{
	return data_[1];
}
std::string& Person::type()
{
	return data_[7];
}
std::string& Person::phone_number()
{
	return data_[2];
}
std::string& Person::qq_number()
{
	return data_[6];
}
void Person::print() const
{
    std::for_each(data_.begin(), data_.end(), [](const std::string& s) { std::cout << s << " "; });
    std::cout << std::endl;
}
std::string Person::item()
{
    std::string ret;
    std::for_each(data_.begin(), data_.end(), [&ret](std::string s) { ret.append(s + " "); });
    ret.append("\n");
    return ret;
}