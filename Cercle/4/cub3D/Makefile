# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 15:26:14 by macbookpro        #+#    #+#              #
#    Updated: 2024/03/29 15:26:15 by macbookpro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
OS	:= $(shell uname)
COMPILER := cc
CFLAGS := -Wall -Wextra -Werror
ifeq ($(OS), Darwin)
	CFLAGS += -Imlx
else
	CFLAGS += -g3
endif

# Directories
SRCS_DIR := ./src/
HEADER_DIR := ./includes/
BUILD_DIR := ./build/
OBJ_DIR := $(BUILD_DIR)obj/
LIBFT_DIR := ./libft/
LIBFT_SRCS := $(wildcard $(LIBFT_DIR)*.c)
LIBFT_OBJS := $(patsubst %.c, %.o, $(LIBFT_SRCS))

# Source files
SRCS := $(addprefix $(SRCS_DIR), main.c hook.c tools.c fractals.c)
OBJS := $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))

# Libraries
ifeq ($(OS), Darwin)
	MLX_DIR := ./minilibx_opengl
	MLX_FLAGS := -framework OpenGL -framework Appkit -l z
else
	MLX_DIR := ./minilibx-linux
	MLX_FLAGS := -lXext -lX11 -lm -lbsd
endif
MLX_PATH := $(MLX_DIR)/libmlx.a

# Targets
NAME := fractol

# Rules
$(LIBFT_DIR)%.o: $(LIBFT_DIR)%.c
	@echo "Compiling $<..."
	@$(COMPILER) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $<..."
	@$(COMPILER) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_OBJS)
	@echo "Linking objects..."
	@$(COMPILER) $(CFLAGS) -I $(HEADER_DIR) -o $@ $^ $(MLX_PATH) $(MLX_FLAGS)
	@echo "$(NAME) has been compiled successfully."

all: $(NAME)

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo "Cleaned up build files."

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) executable has been removed."

re: fclean all

.PHONY: all clean fclean re

