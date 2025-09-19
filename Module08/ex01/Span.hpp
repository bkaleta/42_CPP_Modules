#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
public:
	Span();
	Span(unsigned int N);
	Span(Span const &other);
	~Span();

	Span &operator=(Span const &other);

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	void	getAll();
	std::vector<int> getNumbers();
private:
	unsigned int 		_N;
	std::vector<int> 	_numbers;
};



#endif