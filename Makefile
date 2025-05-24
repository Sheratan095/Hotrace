NAME		= hotrace

VALGRIND =  valgrind --leak-check=full --track-origins=yes --track-fds=yes --show-leak-kinds=all

INCLUDES = -I./includes

SRC = src/main.c \
		src/utils/ft_strchr.c \
		src/utils/ft_strjoin_free_s1.c \
		src/utils/ft_strlen.c \
		src/get_next_line_bonus.c

FLAGS	= -g -O3
FLAGS	+= -Wall -Werror -Wextra

#__asm__

$(NAME): $(SRC)
	@cc $(SRC) $(INCLUDES) $(FLAGS) -lm -o $(NAME)
	@echo "$(GREEN)[$(NAME)]:\t PROJECT COMPILED$(RESET)"

all:$(NAME)

clean:
	@echo "$(RED)[HOTRACE]:\t HOTRACE CLEAN$(RESET)"; \

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)[HOTRACE]:\t HOTRACE FCLEAN$(RESET)"; \

re: fclean all

args =

test: all
	 ./$(NAME)

val: all
	$(VALGRIND) ./$(NAME)

#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m