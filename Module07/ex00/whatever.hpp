#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T &value1, T &value2) {
	T temp = value1;
	value1 = value2;
	value2 = temp;
}

template <typename T>
T min(T const &value1, T const &value2) {
	if (value2 <= value1)
		return (value2);
	else
		return (value1);
}

template <typename T>
T max(T const &value1, T const &value2) {
	if (value2 >= value1)
		return (value2);
	else
		return (value1);
}





#endif