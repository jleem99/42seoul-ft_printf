/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:54:42 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 14:21:10 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "print.h"
#include "specifier.h"
#include "apply_specifier.h"
#include "convert.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>

void	print_char(t_printer *printer, t_specifier *specifier)
{
	char const	c = va_arg(*printer->ap, int);

	if (!specifier->f_minus)
	{
		print_pad(1, printer, specifier);
		printer_putc(printer, c);
	}
	else
	{
		printer_putc(printer, c);
		print_pad(1, printer, specifier);
	}
}

void	print_str(t_printer *printer, t_specifier *specifier)
{
	char	*str;

	str = va_arg(*printer->ap, char *);
	if (!str)
		str = "(null)";
	if (specifier->precision != -1)
	{
		str = ft_substr(str, 0, specifier->precision);
		print(str, printer, specifier);
		free(str);
	}
	else
		print(str, printer, specifier);
}

void	print_ptr(t_printer *printer, t_specifier *specifier)
{
	void *const	ptr = va_arg(*printer->ap, void *);
	char		*str;

	str = uintmax_to_str_16((uintmax_t)ptr, 'a');
	apply_precision_integer(&str, specifier);
	apply_flag_pound(&str, specifier);
	print(str, printer, specifier);
	free(str);
}

void	print_nchar(t_printer *printer, t_specifier *specifier)
{
	void *const	nptr = va_arg(*printer->ap, void *);

	if (specifier->length == 0)
		*((int *)nptr) = printer->nchar;
	else if (specifier->length == 1)
		*((char *)nptr) = printer->nchar;
	else if (specifier->length == 2)
		*((short *)nptr) = printer->nchar;
	else if (specifier->length == 3)
		*((long *)nptr) = printer->nchar;
	else if (specifier->length == 4)
		*((long long *)nptr) = printer->nchar;
	else if (specifier->length == 5)
		*((intmax_t *)nptr) = printer->nchar;
	else if (specifier->length == 6)
		*((size_t *)nptr) = printer->nchar;
	else if (specifier->length == 7)
		*((ptrdiff_t *)nptr) = printer->nchar;
	else
		*((int *)nptr) = printer->nchar;
}

void	print_percent(t_printer *printer, t_specifier *specifier)
{
	char	*str;

	if (!specifier->f_minus && specifier->f_zero && specifier->width > 0)
	{
		str = malloc(specifier->width + 1);
		ft_memset(str, '0', specifier->width - 1);
		str[specifier->width - 1] = '%';
		str[specifier->width] = '\0';
	}
	else
		str = ft_strdup("%");
	print(str, printer, specifier);
	free(str);
}
