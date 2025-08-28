#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(const T &container, int value) {
	typename T::const_iterator it = find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Out of range!");
	return (it);
}

template <typename T>
typename T::iterator easyfind(T &container, int value) {
	typename T::iterator it = find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Out of range!");
	return (it);
}


#endif