SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++ 

FLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SHRUBBERY = rm -f *_shrubbery

NAME = AForm


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(SHRUBBERY)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re