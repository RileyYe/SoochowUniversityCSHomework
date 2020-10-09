#pragma once
#include "Stack.h"
#include <string>
#include <cctype>
#include <vector>
#include <iostream>
static const size_t DEFAULT = 0;
static const size_t NUMBER = 1;
static const size_t SPACE = 2;
static const size_t OPERATOR = 3;
size_t get_status(char c)
{
	if (::std::isdigit(c) || c == '.')
	{
		return NUMBER;
	}
	else if (::std::isspace(c))
	{
		return SPACE;
	}
	else if (c == '(' || c == ')' 
		|| c == '+' || c == '-'
		|| c == '*' || c == '/')
	{
		return OPERATOR;
	}
	return DEFAULT;
}
size_t precedence(char operator_)
{
	switch (operator_)
	{
	case '#':
		return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	default:
		return 3;
	}
}

struct Token{
	std::string literal_;
	std::string type_;
	Token(std::string literal_, std::string type_)
	{
		this->literal_ = literal_;
		this->type_ = type_;
	}
};
double parse(::std::string expr)
{
	expr.push_back(' ');
	std::vector<Token> parsed;
	size_t bracketsLevel = 0;
	size_t status = 0; 
	/*
	** 0 : scan by step
	** 1 : number found
	** 2 : space found
	** 3 : operator found
	*/
	Stack<char> operators_;
	operators_.push('#');
	::std::string token;
	auto cursor1 = expr.begin();
	for (; cursor1 != expr.end(); ++cursor1)
	{
		//if (status = DEFAULT)
		//{
		//	status = get_status(*cursor1);

		//}
		if (get_status(*cursor1) == status)
		{
			if (status == NUMBER)
			{
				token.push_back(*cursor1);
			}
			else if (status == OPERATOR)
			{
				parsed.push_back(Token(std::string(*cursor1, 1), "OPERATOR"));
			}
			continue;
		}
		else{
			if (status == NUMBER)
			{
				if (token == ".")
				{
					::std::cout << "Syntax Error : Invalid Syntax" << std::endl;
					break;
				}
				else 
				{
					parsed.push_back(Token(token, "NUMBER"));
					token.clear();
				}
			}
			status = get_status(*cursor1);
			--cursor1;
		}
	}
	for (auto i = parsed.begin(); i != parsed.end();++i)
	{
		std::cout << i->literal_ << ::std::endl;
	}
	double res;
			//if (status == OPERATOR)
			//{
			//	if (operators_.empty())
			//	{
			//		operators_.push(token[0]);
			//		token.clear();
			//	}
			//	else if (precedence(*cursor1)<precedence(operators_.top()))
			//	{
			//		do {
			//			parsed.push_back(operators_.top());
			//			parsed.append("$");
			//			operators_.pop();
			//		}
			//		while (precedence(*cursor1)>precedence(operators_.top()));
			//	}
			//		operators_.push(token[0]);
			//		
			//		token.clear();
			//}
	return res;
}

