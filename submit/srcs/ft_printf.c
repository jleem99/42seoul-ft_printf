/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 03:13:28 by jleem             #+#    #+#             */
/*   Updated: 2021/06/02 01:32:17 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printer.h"
#include "specifier.h"
#include "print.h"
#include "libft.h"

static int	print_plain(t_printer *printer)
{
	char	c;

	c = printer_getc(printer);
	while (c != '%' && c != '\0')
	{
		printer_putc(printer, c);
		c = printer_popc(printer);
	}
	return (1);
}

static int	print_format(t_printer *printer)
{
	t_specifier	*specifier;

	if (printer_chkc(printer, '%'))
	{
		specifier = parse_specifier(printer);
		if (!specifier)
			return (0);
		if (is_integer(specifier))
			print_integer(printer, specifier);
		else if (is_float(specifier))
			print_float(printer, specifier);
		else if (specifier->specifier == 'c')
			print_char(printer, specifier);
		else if (specifier->specifier == 's')
			print_str(printer, specifier);
		else if (specifier->specifier == 'p')
			print_ptr(printer, specifier);
		else if (specifier->specifier == 'n')
			print_nchar(printer, specifier);
		else if (specifier->specifier == '%')
			print_percent(printer, specifier);
		free(specifier);
	}
	return (1);
}

int			ft_printf(char const *format, ...)
{
	va_list		ap;
	t_printer	printer;

	va_start(ap, format);
	printer = init_printer(NULL, format, &ap);
	while (printer.fmt_idx < printer.fmt_len)
	{
		print_plain(&printer);
		print_format(&printer);
	}
	va_end(ap);
	return (printer.nchar);
}

int			ft_sprintf(char *str, char const *format, ...)
{
	va_list		ap;
	t_printer	printer;

	va_start(ap, format);
	printer = init_printer(str, format, &ap);
	while (printer.fmt_idx < printer.fmt_len)
	{
		print_plain(&printer);
		print_format(&printer);
	}
	va_end(ap);
	printer.putstr[printer.nchar] = '\0';
	return (printer.nchar);
}
