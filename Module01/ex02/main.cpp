#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPTR = &str;
	std::string &strREF = str;

	std::cout << "The memory address of the string variable: " << &str << std::endl;
	std::cout << "The memory address held by stringPTR: " << strPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &strREF << std::endl << std::endl;

	std::cout << "The value of the string variable: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *strPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << strREF << std::endl;
    
    return (0);
}