#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

# define DEBUG 1

class RPN {
private:
	std::stack<int> myStack;
	static bool isValidToken(std::string noSpacesExpression);
	static bool hasTwoDigits(std::string expression);
	static std::string removeSpaces(std::string expression);
	static int calculate(int temp1, int temp2, unsigned char sign);
public:
	RPN();
	RPN(RPN const &other);
	RPN &operator=(RPN const &other);
	~RPN();

	static bool isArgumentCount(int ac);
	void startRPN(std::string expression);
};

#endif