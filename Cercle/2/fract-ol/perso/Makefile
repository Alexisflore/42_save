# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 16:08:31 by alfloren          #+#    #+#              #
#    Updated: 2023/12/13 10:56:27 by alfloren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

OS 			:= $(shell uname)
SRCS_DIR	= ./src/
HEADER_DIR	= ./includes/

SRCS 		= $(addprefix $(SRCS_DIR),\
				main.c hook.c mandelbrot.c julia.c tools.c burningship.c )

OBJS		= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f
MF 			= Makefile

ifeq ($(OS), Darwin)
    CFLAGS	= -Wall -Wextra -Werror -Imlx
else
    CFLAGS	= -Wall -Wextra -Werror -g3
endif

# LIBRARY
ifeq ($(OS), Darwin)
	MLX_DIR 	= ./minilibx-opengl
	MLX_FLAGS	= -framework OpenGL -framework Appkit -l z
	MLX_PATH 	= $(MLX_DIR)/libmlx.a
	# MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
	MLX_DIR 	= ./minilibx-linux
	MLX_FLAGS	= -lXext -lX11 -lm -lbsd
	MLX_PATH	= $(MLX_DIR)/libmlx.a
	# MLX_FLAGS	= -L$(MLX_DIR) -I -g3 -L /usr/X11/lib -L$(HEADER_DIR) -L$(MLX_DIR) -lmlx -I$(MLX_DIR) -lXext -lX11 -lz -lm
endif
MAKE_MLX	= make -C $(MLX_DIR)

# LIBFT
LIBFT_DIR	= ./libft
MAKE_LIBFT	= make -s -C $(LIBFT_DIR)
LIBFT_PATH	= $(LIBFT_DIR)/libft.a

.c.o:
			@/bin/echo -n .
			@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(MF) $(OBJS) libft mlx
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) $(MLX_PATH) $(MLX_FLAGS)  -o $(NAME)
			@echo "\n${GREEN}> fract-ol was successfuly compiled 🎉${END}"

all: 		$(NAME)

clean:
			@$(RM) $(OBJS)
			@$(MAKE_LIBFT) clean
			@$(MAKE_MLX) clean
			@echo "${YELLOW}> All objects files of fract-ol have been deleted ❌${END}"

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE_LIBFT) fclean
			@$(MAKE_MLX) clean
			@echo "${YELLOW}> Cleaning of fract-ol has been done ❌${END}"

re:			fclean all

libft:
			@$(MAKE_LIBFT) all bonus

mlx:
			@$(MAKE_MLX)

.PHONY: all clean fclean re libft mlx

# OBJ_PATH = objs
# OBJ_NAME = $(SRC_NAME:.c=.o)

# CC = clang
# CFLAGS = -Wall -Werror -Wextra

# CPPFLAGS = -I includes -I libft/includes

# LDFLAGS = -L libft
# LDLIBS = -O2 -lft -lm -lmlx -framework OpenGL -framework AppKit

# SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
# OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# all: $(NAME)

# $(NAME): $(OBJ)
# 	@make -C libft
# 	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
# 	@echo "Compilation of Fractol:	\033[1;32mOK\033[m"

# $(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
# 	@mkdir $(OBJ_PATH) 2> /dev/null || true
# 	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

# clean:
# 	@make -C libft clean
# 	@rm -f $(OBJ)
# 	@rmdir $(OBJ_PATH) 2> /dev/null || true
# 	@echo "Fractol: Removing Objs"

# fclean: clean
# 	@make -C libft fclean
# 	@rm -f $(NAME)
# 	@echo "Fractol : Removing Fractol"

# re: fclean all

# .PHONY: all clean fclean re
