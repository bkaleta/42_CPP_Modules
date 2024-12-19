# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/14 21:09:36 by bkaleta           #+#    #+#              #
#    Updated: 2024/12/19 14:08:07 by bkaleta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Kompilator i flagi
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror 

# Nazwa pliku wykonywalnego
TARGET = megaphone

# Pliki źródłowe i obiektowe
SRC = megaphone.cpp
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
