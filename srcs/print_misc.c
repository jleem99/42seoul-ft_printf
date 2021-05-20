/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:54:42 by jleem             #+#    #+#             */
/*   Updated: 2021/05/21 00:10:20 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "print.h"
#include "specifier.h"
#include "apply_specifier.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

void	print_char(t_printer *printer, t_specifier *specifier)
{
	if (!specifier->f_minus)
		while (--specifier->width > 0)
			printer_putc(printer, ' ');
	printer_putc(printer, va_arg(*printer->ap, int));
	if (specifier->f_minus)
		while (--specifier->width > 0)
			printer_putc(printer, ' ');
}

void	print_str(t_printer *printer, t_specifier *specifier) // validate malloc
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

void	print_ptr(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;
	void	*ptr;

	ptr = va_arg(*printer->ap, void *);
	if (!ptr)
		str = ft_strdup("0");
	else
		str = ft_uimtoa_16((uintmax_t)ptr, 'a');
	specifier->f_pound = 1;
	apply_flag_integer(&str, specifier, 0);
	print(str, printer, specifier);
	free(str);
}

void	print_nchar(t_printer *printer, t_specifier *specifier)
{
	int		*nchar;

	nchar = va_arg(*printer->ap, int *);
	*nchar = printer->nchar;
}

void	print_percent(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	if (!specifier->f_minus && specifier->width > 1 && specifier->f_zero)
	{
		str = malloc(specifier->width + 1); // check
		ft_memset(str, '0', specifier->width - 1);
		str[specifier->width - 1] = '%';
		str[specifier->width] = '\0';
	}
	else
		str = ft_strdup("%");
	print(str, printer, specifier);
	free(str);
}
