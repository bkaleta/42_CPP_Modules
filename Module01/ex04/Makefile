# Kompilator i flagi
CXX = c++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Nazwa pliku wykonywalnego
TARGET = Sed_is_for_losers

# Pliki źródłowe i obiektowe
SRC = main.cpp loser.cpp
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
