# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaleta <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/14 21:28:39 by bkaleta           #+#    #+#              #
#    Updated: 2025/01/04 12:55:06 by bkaleta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Kompilator i flagi
CXX = c++
CXXFLAGS = -std=c++17 -std=c++98 -Wall -Wextra -Werror 

# Nazwa pliku wykonywalnego
TARGET = phonebook

# Pliki źródłowe i obiektowe
SRC = main.cpp phonebook.cpp contact.cpp
OBJ = $(SRC:.cpp=.o)

# Domyślny cel
all: $(TARGET)

# Reguła do budowania programu
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Reguła do kompilacji plików .cpp na pliki .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Czyszczenie plików obiektowych i programu
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: all clean
