NAME = cub3D

OS 			:= $(shell uname)
SRCS_DIR	= ./src/
HEADER_DIR	= ./includes/

SRCS 		= $(addprefix $(SRCS_DIR),\
				main.c\
				parsing/check_args.c\
				rendering/render.c\
				parsing/colors.c\
				parsing/initialize.c\
				move/move.c\
				rendering/find_values.c\
				rendering/check_lines.c\
				rendering/draw_pixels.c\
				rendering/drawing.c\
				move/player_move.c\
			)

OBJS		= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f
MF 			= Makefile

ifeq ($(OS), Darwin)
    CFLAGS	= -Wall -Wextra -Werror -Imlx -I/opt/X11/include
else
    CFLAGS	= -Wall -Wextra -Werror -g3
endif

# LIBRARY
ifeq ($(OS), Darwin)
	MLX_DIR 	= ./minilibx_opengl
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
			@echo "\n${GREEN}> cub3D was successfuly compiled 🎉${END}"

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
# OS 			:= $(shell uname)
# SRCS_DIR	= ./src/
# HEADER_DIR	= ./includes/

# SRCS 		= $(addprefix $(SRCS_DIR),\
# 				main.c \
# 				/parsing/check_args.c \)

# OBJS		= $(SRCS:.c=.o)

# CC			= cc
# RM			= rm -f
# MF 			= Makefile

# ifeq ($(OS), Darwin)
#     CFLAGS	= -Wall -Wextra -Werror -Imlx -I/opt/X11/include
# else
#     CFLAGS	= -Wall -Wextra -Werror -g3
# endif

# # LIBRARY
# ifeq ($(OS), Darwin)
# 	MLX_DIR 	= ./minilibx_opengl
# 	MLX_FLAGS	= -framework OpenGL -framework Appkit -l z 
# 	MLX_PATH 	= $(MLX_DIR)/libmlx.a
# 	# MLX_FLAGS	= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
# else
# 	MLX_DIR 	= ./minilibx-linux
# 	MLX_FLAGS	= -lXext -lX11 -lm -lbsd
# 	MLX_PATH	= $(MLX_DIR)/libmlx.a
# 	# MLX_FLAGS	= -L$(MLX_DIR) -I -g3 -L /usr/X11/lib -L$(HEADER_DIR) -L$(MLX_DIR) -lmlx -I$(MLX_DIR) -lXext -lX11 -lz -lm
# endif
# MAKE_MLX	= make -C $(MLX_DIR)

# # LIBFT
# LIBFT_DIR	= ./libft
# MAKE_LIBFT	= make -s -C $(LIBFT_DIR)
# LIBFT_PATH	= $(LIBFT_DIR)/libft.a

# .c.o:
# 	@/bin/echo -n .
# 	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

# $(NAME):	$(MF) $(OBJS) libft mlx
# 	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) $(MLX_PATH) $(MLX_FLAGS)  -o $(NAME)
# 	@echo "\n${GREEN}> fract-ol was successfuly compiled 🎉${END}"

# all: 		$(NAME)

# clean:
# 	@$(RM) $(OBJS)
# 	@$(MAKE_LIBFT) clean
# 	@$(MAKE_MLX) clean
# 	@echo "${YELLOW}> All objects files of fract-ol have been deleted ❌${END}"

# fclean:		clean
# 	@$(RM) $(NAME)
# 	@$(MAKE_LIBFT) fclean
# 	@$(MAKE_MLX) clean
# 	@echo "${YELLOW}> Cleaning of fract-ol has been done ❌${END}"

# re:			fclean all

# libft:
# 	@$(MAKE_LIBFT) all bonus

# mlx:
# 	@$(MAKE_MLX)

# .PHONY: 	all clean fclean re libft mlx