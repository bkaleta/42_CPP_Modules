#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		~Array();

		Array &operator=(Array const &other);
		T &operator[](unsigned int i);

		int size() const;

		class  IndexIsOutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	private:
		T *array;
		unsigned int len;
};

template <typename T>
Array<T>::Array() : array(NULL), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), len(n) {
	for (unsigned int i = 0; i < this->len; i++) {
		array[i] = T();
	}
}

template <typename T>
Array<T>::Array(Array const &other) : array(new T[other.len]), len(other.len) {
	for (unsigned int i = 0; i < this->len; i++) {
		array[i] = other.array[i];
	}
}

template <typename T>
Array<T>::~Array() {
	delete [] array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
	if (this != &other) {
		delete [] this->array;
		this->len = other.len;
		this->array = new T[this->len];
		for (unsigned int i = 0; i < this->len; i++) {
			this->array[i] = other.array[i];
		}
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
	if (i >= len)
		throw IndexIsOutOfBoundsException();
	return (array[i]); 
}

template <typename T>
int Array<T>::size() const {
	return (len);
}

template <typename T>
char const *Array<T>::IndexIsOutOfBoundsException::what() const throw() {
	return ("index is out of bounds!");
}

#endif