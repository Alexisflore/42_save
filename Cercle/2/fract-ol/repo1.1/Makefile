# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 12:18:57 by tglandai          #+#    #+#              #
#    Updated: 2023/12/19 14:59:42 by alfloren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = srcs
SRC_NAME = main.c hook.c mandelbrot.c julia.c tools.c burningship.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft/includes

LDFLAGS = -L libft
MLX_DIR 	= ./minilibx-linux
MLX_PATH	= $(MLX_DIR)/libmlx.a
LDLIBS = -lXext -lX11 -lm -lbsd

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LDFLAGS) $(MLX_PATH) $(LDLIBS) $^ -o $@
	@echo "Compilation of Fractol:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Fractol: Removing Objs"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Fractol : Removing Fractol"

re: fclean all

.PHONY: all clean fclean re
