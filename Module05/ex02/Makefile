# =======================
# Project: cpp05 - Repetition and Exceptions
# =======================

NAME        = AForm
CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98

# ---- sources / objects ----
BASIC       = main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm
SRCS        = $(addsuffix .cpp, $(BASIC))
OBJS        = $(addsuffix .o, $(BASIC))
SHRUBBERY 	= rm -f *_shrubbery

# ---- colors ----
GREEN       = \033[0;32m
RESET       = \033[0m

# ---- default ----
all: $(NAME)

$(NAME): $(OBJS)
	@$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)✔️  Build complete: '$(NAME)' created$(RESET)"

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(SHRUBBERY)
	@echo "$(GREEN)🧹 Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)🗑️  Executable '$(NAME)' removed$(RESET)"

re: fclean all

run: re
	@echo "$(GREEN)▶️  Run '$(NAME)'$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re run

