/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 00:31:45 by jleem             #+#    #+#             */
/*   Updated: 2021/02/21 02:00:09 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "libft.h"

t_printer	init_printer(char const *format, va_list *ap)
{
	t_printer	printer;

	printer.fmt = format;
	printer.fmt_idx = 0;
	printer.fmt_len = ft_strlen(printer.fmt);
	printer.cursor = 0;
	printer.nchar = 0;
	printer.ap = ap;
	return (printer);
}

char		printer_getc(t_printer *printer)
{
	if (printer->fmt_idx >= printer->fmt_len)
		return (-1);
	else
		return (printer->fmt[printer->fmt_idx]);
}

void		printer_putc(t_printer *printer, char c)
{
	ft_putchar_fd(c, 1);
	printer->nchar++;
	if (c == '\n')
		printer->cursor = 0;
	else
		printer->cursor++;
}

int			printer_chkc(t_printer *printer, char c)
{
	if (printer_getc(printer) == c)
	{
		printer->fmt_idx++;
		return (1);
	}
	return (0);
}
