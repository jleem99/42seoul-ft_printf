# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 03:34:26 by jleem             #+#    #+#              #
#    Updated: 2021/02/18 07:07:08 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
AR			= ar -rcs
WFLAGS		= -Wall -Wextra
CFLAGS		= $(WFLAGS) -I$(INCDIR)

NAME		= libftprintf.a
SRCDIR		= srcs
INCDIR		= includes
SRCS		= $(wildcard $(SRCDIR)/*.c) # Use explicit variables
OBJS		= $(SRCS:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
	$(AR) $@ $^

clean		:
	rm -f $(OBJS)

fclean		: clean
	rm -f $(NAME)

re			: fclean all

test		: re # To be removed
	$(CC) main.c $(NAME) $(CFLAGS) -o test.out
	./test.out

.PHONY		: all clean fclean re
