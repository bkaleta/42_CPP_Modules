# ============================================================
# Project: cpp09 - STL
# ============================================================

NAME        = btc
CPP         = c++
CPPFLAGS    = -Wall -Wextra -Werror -std=c++98

# ---- sources / objects ----
BASIC       = main
SRCS        = $(addsuffix .cpp, $(BASIC))
OBJS        = $(addsuffix .o, $(BASIC))

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
	@rm -f $(OBJS)
	@echo "$(GREEN)🧹 Object files removed$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)🗑️  Executable '$(NAME)' removed$(RESET)"

re: fclean all

run: re
	@echo "$(GREEN)▶️  Run '$(NAME)'$(RESET)"
	@./$(NAME)

.PHONY: all clean fclean re run

