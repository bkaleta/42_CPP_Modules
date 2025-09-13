#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

class RPN {
private:
	std::stack<int> myStack;
public:
	RPN();
	RPN(RPN const &other);
	RPN &operator=(RPN const &other);
	~RPN();
	
};

bool isArgumentCount(int ac);
bool isValidToken(std::string noSpacesExpression);
std::string removeSpaces(std::string expression);
void startRPN(std::string expression);


#endif