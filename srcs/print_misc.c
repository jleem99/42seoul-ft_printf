/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:54:42 by jleem             #+#    #+#             */
/*   Updated: 2021/05/21 23:20:18 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "print.h"
#include "specifier.h"
#include "apply_specifier.h"
#include "int_to_str.h"
#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>

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
	(void)specifier;
	*((int *)va_arg(*printer->ap, int *)) = printer->nchar;
}

void	print_percent(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	if (!specifier->f_minus && specifier->f_zero)
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
