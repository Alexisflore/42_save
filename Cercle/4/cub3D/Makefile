SHELL		:= /bin/sh

NAME		:= cub3D

SRC_DIR		:= ./src
BUILD_DIR	:= ./build
INCLUDE_DIR	:= ./include
LIBFT_DIR	:= ./lib/libft
LIBMLX_DIR	:= ./lib/minilibx-linux

SRC_FILES	:=	main.c \
				parsing/check_args.c \
				rendering/render.c \
				parsing/colors.c \
				parsing/initialize.c \
				move/move.c \
				rendering/find_values.c \
				rendering/check_lines.c \
				rendering/draw_pixels.c \
				rendering/drawing.c \
				move/player_move.c \
				free/free_data.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				parsing/test_check_args.c \
				parsing/init_parsing_values.c \
				parsing/handling_errors.c \
				parsing/boolean_test.c \
				parsing/check_data.c \
				parsing/check_data1.c \
				parsing/parsing_utils.c \
				parsing/creates_data.c \

OBJ_FILES		:= $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
DEP_FILES		:= $(OBJ_FILES:.o=.d)

CFLAGS		:= -Wall -Wextra -Werror -MMD -MP -g3
CPPFLAGS	:= -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

LDFLAGS		:= -L$(LIBFT_DIR)
LDLIBS		:= -lft

ifeq ($(shell uname -s),Linux)
	CPPFLAGS	+= -I$(LIBMLX_DIR)
	LDFLAGS		+= -L$(LIBMLX_DIR)
	LDLIBS		+= -lmlx_Linux -lm -lXext -lX11
else ifeq ($(shell uname -s),Darwin)
	LIBMLX_DIR	:= ./lib/minilibx-opengl
	CPPFLAGS	+= -I$(LIBMLX_DIR)
	LDFLAGS		+= -L$(LIBMLX_DIR)
	LDLIBS		+= -lmlx -lm -framework OpenGL -framework AppKit
else
	$(error Unsupported operating system)
endif

.PHONY: all clean fclean re lib cleanlib fcleanlib relib cleanall fcleanall \
reall

all: lib $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(DEP_FILES)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) -o $(NAME)

lib:
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(LIBMLX_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

cleanlib:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

fcleanlib:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(LIBMLX_DIR)

relib: fcleanlib lib

cleanall: cleanlib clean

fcleanall: fcleanlib fclean

reall: fcleanall all
