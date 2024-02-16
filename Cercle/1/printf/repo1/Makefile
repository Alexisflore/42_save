# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 17:58:46 by alfloren          #+#    #+#              #
#    Updated: 2023/11/20 15:45:01 by alfloren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME			= libftprintf.a

SRCS			=		 ft_printf.c \
					ft_itoa.c \
					ft_print_hex.c \
					ft_print_ptr.c \
					ft_printf.c \
					ft_putchar_fd.c \
					ft_print_unsigned.c \
					ft_printf_utils.c

# SRCS_DIR	 = ./srcs/

# SRCS		 =		$(addprefix $(SRCS_DIR), $(SRC))

CC			= cc

FLAGS		= -Wall -Wextra -Werror

OBJS		= ${SRCS:.c=.o}

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}
			@echo "ft_printf object files cleaned!"

fclean:		clean
			rm -f ${NAME}
			@echo "ft_printf executable files cleaned!"

re:			fclean all
			@echo "Cleaned and rebuilt everything for ft_printf!"

.PHONY:		all clean fclean re
