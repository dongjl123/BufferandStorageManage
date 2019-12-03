#include <ui.hpp>
#include <iostream>
#include <string.h>

#define RESET "\033[0m"
#define BLACK "\033[30m" 
#define RED "\033[31m" 
#define GREEN "\033[32m" 
#define YELLOW "\033[33m" 
#define BLUE "\033[34m" 
#define MAGENTA "\033[35m" 
#define CYAN "\033[36m" 
#define WHITE "\033[37m" 
#define BOLDBLACK "\033[1m\033[30m" 
#define BOLDRED "\033[1m\033[31m" 
#define BOLDGREEN "\033[1m\033[32m" 
#define BOLDYELLOW "\033[1m\033[33m" 
#define BOLDBLUE "\033[1m\033[34m" 
#define BOLDMAGENTA "\033[1m\033[35m" 
#define BOLDCYAN "\033[1m\033[36m" 
#define BOLDWHITE "\033[1m\033[37m" 

void IUI::print(char *message, int length) 
{
	std::string out(message, length);
	std::cout << BOLDWHITE << "[info] " << RESET << out << std::endl;
}


void IUI::print(std::string message) 
{
	std::cout << BOLDWHITE << "[info] " << RESET << GREEN << message << std::endl;
}

void IUI::error(std::string message, int length) 
{
	std::string out(message, length);
	std::cerr << BOLDRED << "[error] " << RESET << out << std::endl;
}

void IUI::error(std::string message) 
{
	std::cerr << BOLDRED << "[error] " << RESET << message << std::endl;
}

void IUI::debug(char *message, int length) 
{
	std::string out(message, length);
	std::cerr << BLUE << "[debug] " << RESET << out << std::endl;
}

void IUI::debug(std::string message) 
{
	std::cerr << BLUE << "[debug] " << RESET << message << std::endl;
}

void IUI::result(std::string message, int num)
{
	std::cerr << BOLDBLACK << "[result] " << RESET << MAGENTA << message << num << std::endl;
}

void IUI::rule(std::string message)
{
	int len = message.length();
	int max_len = 80;
	int rule_len = (80-len)/2;
	string rule = "";
	for (size_t i = 0; i < rule_len; i++)
	{
		rule = rule + "=";
	}
	cerr<< BOLDYELLOW <<rule;
	std::cout << BOLDMAGENTA << message ;
	cerr<< BOLDYELLOW <<rule;
	std::cout << std::endl;
	
}