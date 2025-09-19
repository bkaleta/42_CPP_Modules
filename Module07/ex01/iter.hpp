#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T_arr, typename T_func>
void iter(T_arr *arr, size_t len, T_func function) {
	for (size_t i = 0; i < len; i++)
		function(arr[i]);
}

template <typename T_arr, typename T_func>
void iter(T_arr const *arr, size_t len, T_func function) {
	for (size_t i = 0; i < len; i++)
		function(arr[i]);
}

#endif