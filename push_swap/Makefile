NAME = push_swap

BONUS_NAME = checker

LIBFT = libft

LIBFTM = libft/libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFILES_1 = push_swap.c

CFILES_2 = function.c \
			function2.c \
			function3.c \
			rules_a.c \
			rules_b.c \
			rules_2.c

BONUS_FILES = checker.c get_next_line.c

OBJS_1 = $(CFILES_1:.c=.o)

OBJS_2 = $(CFILES_2:.c=.o)

BONUS_OBJS = $(BONUS_FILES:.c=.o)


$(NAME): $(OBJS_1) $(OBJS_2)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) $(LIBFTM) -o $(NAME)
	@echo "\033[0;32m\nPush_swap is ready\n\033[0m"

$(BONUS_NAME):  $(BONUS_OBJS) $(OBJS_2)
	make -C $(LIBFT)
	@$(CC) $(CFLAGS)  $(OBJS_2) $(LIBFTM) $(BONUS_OBJS) -o $(BONUS_NAME)
	@echo "\033[0;32m\nChecker is ready\033[0m"

all: $(NAME) $(BONUS_NAME)
	@echo "\033[0;32m\nAll files compiled\n\033[0m"

bonus: ${BONUS_NAME}
	@echo "\033[0;32m\nBonus files compiled\n\033[0m"

clean:
		@rm -f $(OBJS_1) $(OBJS_2) $(BONUS_OBJS)
		@make clean -C $(LIBFT)
		@echo "\033[0;32m\nObjects files deleted\n\033[0m"

fclean: clean
		@make fclean -C $(LIBFT)
		@rm -rf $(NAME) $(BONUS_NAME)
		@echo "\033[0;32m\nArchive file deleted\n\033[0m"

re: fclean all
