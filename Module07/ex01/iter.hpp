#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T_arr, typename T_func>
void iter(T_arr *arr, size_t len, T_func function) {
	size_t i = 0;

	while (i < len) {
		function(arr[i]);
		i++;
	} 
}

template <typename T_arr, typename T_func>
void iter(T_arr const *arr, size_t len, T_func function) {
	size_t i = 0;

	while (i < len) {
		function(arr[i]);
		i++;
	} 
}




#endif