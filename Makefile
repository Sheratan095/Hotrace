NAME		= hotrace

TESTS = test01.htr \
			test02.htr \
			test03.htr \
			test04.htr \
			test05.htr


VALGRIND =  valgrind --leak-check=full --track-origins=yes --track-fds=yes --show-leak-kinds=all

INCLUDES = -I./includes

SRC = src/main.c \
		src/utils/ft_putstr_fd.c \
		src/utils/ft_strchr.c \
		src/utils/ft_strjoin_free_s1.c \
		src/utils/ft_strlen.c \
		src/utils/ft_strlcpy.c \
		src/utils/ft_memcpy.c \
		src/utils/ft_bzero.c \
		src/utils/ft_calloc.c \
		src/utils/ft_memset.c \
		src/utils/get_next_line_bonus.c \
		src/ft_hash.c \
		src/data.c \
		src/parser.c \
		src/insertion.c \
		src/search.c \
		src/print_msg.c

FLAGS	= -g
FLAGS	+= -Wall -Werror -Wextra

#__asm__

$(NAME): $(SRC)
	@cc $(SRC) $(INCLUDES) $(FLAGS) -o $(NAME)
	@echo "$(GREEN)[$(NAME)]:\t PROJECT COMPILED$(RESET)"

all:$(NAME)

clean:
	@echo "$(RED)[HOTRACE]:\t HOTRACE CLEAN$(RESET)"; \

fclean: clean
	@rm -f $(NAME) giacomo tbeauzam test_result.txt
	@echo "$(RED)[HOTRACE]:\t HOTRACE FCLEAN$(RESET)"; \


re: fclean all

args =

val_test: all
	$(VALGRIND) ./$(NAME) < tests/test01.htr
	@echo "$(BLUE)[HOTRACE]:\t[ENTER] NEXT TEST$(RESET)"
	@read ans
	$(VALGRIND) ./$(NAME) < tests/test02.htr
	@echo "$(BLUE)[HOTRACE]:\t[ENTER] NEXT TEST$(RESET)"
	@read ans
	$(VALGRIND) ./$(NAME) < tests/test03.htr
	@echo "$(BLUE)[HOTRACE]:\t[ENTER] NEXT TEST$(RESET)"
	@read ans
	$(VALGRIND) ./$(NAME) < tests/test04.htr
	@echo "$(BLUE)[HOTRACE]:\t[ENTER] NEXT TEST$(RESET)"
	@echo "$(GREEN)[HOTRACE]:\t ALL TESTS PASSED$(RESET)"

test: all
	time ./$(NAME) < tests/test01.htr
	@echo "$(BLUE)[HOTRACE]:\t[ENTER] NEXT TEST$(RESET)"
	@read ans
	time ./$(NAME) < tests/test02.htr
	@echo "$(BLUE)[HOTRACE]:\t[ENTER] NEXT TEST$(RESET)"
	@read ans
	time ./$(NAME) < tests/test03.htr
	@echo "$(BLUE)[HOTRACE]:\t[ENTER] NEXT TEST$(RESET)"
	@read ans
	time ./$(NAME) < tests/test04.htr
	@echo "$(BLUE)[HOTRACE]:\t[ENTER] NEXT TEST$(RESET)"
	@read ans
	time ./$(NAME) < tests/test05.htr
	@echo "$(BLUE)[HOTRACE]:\t[ENTER] NEXT TEST$(RESET)"
	@read ans
	time ./$(NAME) < tests/test06.htr
	@echo "$(GREEN)[HOTRACE]:\t ALL TESTS PASSED$(RESET)"

val: all
	$(VALGRIND) ./$(NAME) $(REDIR)

#COLORS

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
RESET=\033[0m