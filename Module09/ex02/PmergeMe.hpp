#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <exception>
# include <string>
# include <deque>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(PmergeMe const &other);
	PmergeMe(int ac, char **av);
	PmergeMe &operator=(PmergeMe const &other);
	~PmergeMe();
	void startPmergeMe();

	class MyErrorException : public std::exception {
		public:
			MyErrorException(const std::string &message) : message(message) {}
			virtual ~MyErrorException() throw() {}
			const char *what() const throw() {
				return message.c_str();
			}
		private:
			std::string message;
	};
private:
	std::vector<int> myVector;
	std::deque<int> myDeque;
};

#endif