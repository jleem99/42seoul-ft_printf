/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 03:13:28 by jleem             #+#    #+#             */
/*   Updated: 2021/02/18 07:15:46 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_plain(t_printer *printer)
{
	char	c;
	int		sidx;

	c = printer->fmt[printer->fmt_idx];
	sidx = printer->fmt_idx;
	while (c != '%' && c != '\0')
	{
		write(1, &c, 1);
		if (c == '\n')
			printer->cursor = 0;
		else
			printer->cursor++;
		c = printer->fmt[++printer->fmt_idx];
	}
	return (printer->fmt_idx - sidx);
}

static int	print_format(t_printer *printer)
{
	char	c;

	if (printer->fmt[printer->fmt_idx] == '%')
	{
		
	}
	else
		return (0);
}

static int	print(t_printer *printer)
{
	int		nchar;

	nchar = 0;
	nchar += print_plain(printer);
	nchar += print_format(printer);

	return (nchar);
}

#include <string.h>

static t_printer	set_printer(char const *format, va_list *ap)
{
	t_printer	printer;

	printer.fmt = format;
	printer.fmt_idx = 0;
	printer.fmt_len = strlen(printer.fmt); // Replace to ft_strlen
	printer.cursor = 0;
	printer.ap = ap;
	return (printer);
}

int			ft_printf(char const *format, ...)
{
	va_list		ap;
	int			nchar;
	int			nchar_new;
	t_printer	printer;

	va_start(ap, format);
	printer = set_printer(format, &ap);

	nchar_new = print(&printer);
	nchar = nchar_new;
	while (nchar_new)
	{
		nchar_new = print(&printer);
		nchar += nchar_new;
	}

	va_end(ap);
	return (nchar);
}
