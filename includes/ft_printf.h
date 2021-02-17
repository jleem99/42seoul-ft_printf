/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 03:13:39 by jleem             #+#    #+#             */
/*   Updated: 2021/02/18 07:00:31 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_printer
{
	char const	*fmt;
	int			fmt_idx;
	int			fmt_len;
	int			cursor;
	int			nchar;
	va_list		*ap;
}				t_printer;

int		ft_printf(char const *format, ...);

#endif
