#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

class RPN {
public:
	RPN();
	RPN(RPN const &other);
	RPN &operator=(RPN const &other);
	~RPN();
	
	static bool isArgumentCount(int ac);
	static void startProgram(int ac, const char* expression);
	void startRPN(std::string expression);
private:
	std::stack<int> myStack;
	static bool isValidToken(std::string noSpacesExpression);
	static bool hasTwoDigits(std::string expression);
	static std::string removeSpaces(std::string expression);
	static int calculate(int temp1, int temp2, unsigned char sign);
	void performRPN(const std::string noSpacesExpression);
};

#endif