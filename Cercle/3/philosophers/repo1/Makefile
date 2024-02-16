NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

CFILES = src/main.c src/utils/init.c src/utils/utils.c \
			src/utils/threads.c src/utils/actions.c \

OBJECTS = $(CFILES:.c=.o)

all: libraries $(NAME)

%.o : %.c
	@echo Compiling $<...
	@$(CC) $(CFLAGS) -c -o $@ $<

libraries:
$(NAME): $(OBJECTS)
	@echo Compiling $(CFILES)...
	@echo Finished [$(CFILES)]
	@echo
	@echo Compiling $(NAME)...
	@$(CC) $(CFLAGS) $(LIBFT_LIB) $(PRINTF_LIB) $(OBJECTS) -o $(NAME)
	@echo Finished $(NAME)

clean:
	@rm -f $(OBJECTS)
	@echo Removed $(OBJECTS)
	@echo Removed libraries.o

fclean: clean
	@rm -f $(NAME)
	@echo Removed $(NAME)

re: fclean all

norm:
	norminette ft_printf utils checker

#run:	all

.PHONY: all clean fclean re norm
