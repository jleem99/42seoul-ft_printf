# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 03:34:26 by jleem             #+#    #+#              #
#    Updated: 2021/05/31 04:36:40 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
AR			= ar -rcs
WFLAGS		= -Wall -Wextra
INC_FLAGS	= -I$(INCDIR) -I$(LIBFTDIR)
CFLAGS		= $(WFLAGS) $(INC_FLAGS) -g # To be removed
# CFLAGS		= $(WFLAGS) $(INC_FLAGS) -g -fsanitize=address # To be removed
# CFLAGS		+= -Wno-unused-parameter -Wno-unused-variable # To be removed

NAME		= libftprintf.a
SRCDIR		= srcs
INCDIR		= includes
SRCS		= $(wildcard $(SRCDIR)/*.c) # Use explicit variables
OBJS		= $(SRCS:.c=.o)

LIBFT		= $(addprefix $(LIBFTDIR), libft.a)
LIBFTDIR	= Libft/

all			: $(NAME)

$(NAME)		: $(LIBFT) $(OBJS)
	cp $(LIBFT) $@
	$(AR) $@ $(OBJS)

$(LIBFT)	:
	$(MAKE) -C $(LIBFTDIR)		CC='$(CC)' CFLAGS='$(CFLAGS)'	bonus

clean		:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJS)

fclean		: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(NAME)

re			: fclean all

debug		: all # To be removed
	$(CC) main.c $(NAME) $(CFLAGS) -o test.out

test		: CFLAGS += -Wno-format
test		: debug # To be removed
	./test.out

profile		: CFLAGS += -w
profile		: CFLAGS += -D TESTMODE=1
profile		: debug
	bash -c "time ./test.out > /dev/null"

reference	: CFLAGS += -w
reference	: CFLAGS += -D TESTMODE=0
reference	: debug
	bash -c "time ./test.out > /dev/null"

.PHONY		: all clean fclean re
