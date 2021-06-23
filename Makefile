# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/21 03:34:26 by jleem             #+#    #+#              #
#    Updated: 2021/06/23 18:07:18 by jleem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
AR				= ar -rcs
WFLAGS			= -Wall -Wextra -Werror
INC_FLAGS		= -I$(INCDIR) -I$(LIBFTDIR)
CFLAGS			= $(WFLAGS) $(INC_FLAGS)

NAME			= libftprintf.a
SRCDIR			= src
OBJDIR			= build
INCDIR			= includes

SRCS			= $(patsubst %, $(SRCDIR)/%, \
					apply_specifier.c \
					apply_specifier_utils.c \
					apply_specifier_utils2.c \
					convert_float_to_str.c \
					convert_float_to_str_e.c \
					convert_float_to_str_utils.c \
					convert_float_to_str_utils2.c \
					convert_int_to_str.c \
					ft_printf.c \
					getarg.c \
					parse_specifier.c \
					print.c \
					print_float.c \
					print_integer.c \
					print_misc.c \
					printer.c \
					specifier_utils.c)
OBJS			= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

LIBFT			= $(addprefix $(LIBFTDIR)/, libft.a)
LIBFTDIR		= Libft

all				: $(NAME)

$(NAME)			: $(LIBFT) $(OBJS)
	cp $(LIBFT) $@
	$(AR) $@ $(OBJS)

$(OBJDIR)		:
	mkdir -p $@

$(OBJDIR)/%.o	: $(SRCDIR)/%.c $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)		:
	$(MAKE) -j 8 -C $(LIBFTDIR) bonus

clean			:
	$(MAKE) -C $(LIBFTDIR) clean
	$(RM) -r $(OBJDIR)/*

fclean			: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(NAME)

re				: fclean all

bonus			: all

.PHONY			: all clean fclean re bonus
