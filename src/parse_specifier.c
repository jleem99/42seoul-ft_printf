/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:57:57 by jleem             #+#    #+#             */
/*   Updated: 2021/07/08 17:52:39 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include "printer.h"
#include "libft_bonus.h"
#include <stdlib.h>
#include <stdarg.h>

static int	parse_flag(t_specifier *specifier, t_printer *printer)
{
	char	c;

	c = printer_getc(printer);
	while (c != '\0' && ft_strchr("-+ #0", c))
	{
		if (c == '-')
			specifier->f_minus = 1;
		else if (c == '+')
			specifier->f_plus = 1;
		else if (c == ' ')
			specifier->f_space = 1;
		else if (c == '#')
			specifier->f_pound = 1;
		else if (c == '0')
			specifier->f_zero = 1;
		c = printer_popc(printer);
	}
	return (1);
}

static int	parse_width(t_specifier *specifier, t_printer *printer)
{
	char	c;

	specifier->width = -1;
	c = printer_getc(printer);
	if (c == '*')
	{
		specifier->width = va_arg(*printer->ap, int);
		if (specifier->width < 0)
		{
			specifier->f_minus = 1;
			specifier->width *= -1;
		}
		printer_popc(printer);
	}
	else if (ft_isdigit(c))
	{
		specifier->width = 0;
		while (ft_isdigit(c))
		{
			specifier->width = specifier->width * 10 + c - '0';
			c = printer_popc(printer);
		}
	}
	return (1);
}

static int	parse_precision(t_specifier *specifier, t_printer *printer)
{
	char	c;

	specifier->precision = -1;
	if (!printer_chkc(printer, '.'))
		return (1);
	c = printer_getc(printer);
	if (c == '*')
	{
		specifier->precision = va_arg(*printer->ap, int);
		if (specifier->precision < 0)
			specifier->precision = -1;
		printer_popc(printer);
	}
	else if (ft_isdigit(c))
	{
		specifier->precision = 0;
		while (ft_isdigit(c))
		{
			specifier->precision = specifier->precision * 10 + c - '0';
			c = printer_popc(printer);
		}
	}
	else
		specifier->precision = 0;
	return (1);
}

static int	parse_length(t_specifier *specifier, t_printer *printer)
{
	if (printer_chkc(printer, 'h'))
	{
		specifier->length = 2;
		if (printer_chkc(printer, 'h'))
			specifier->length = 1;
	}
	else if (printer_chkc(printer, 'l'))
	{
		specifier->length = 3;
		if (printer_chkc(printer, 'l'))
			specifier->length = 4;
	}
	else if (printer_chkc(printer, 'j'))
		specifier->length = 5;
	else if (printer_chkc(printer, 'z'))
		specifier->length = 6;
	else if (printer_chkc(printer, 't'))
		specifier->length = 7;
	else if (printer_chkc(printer, 'L'))
		specifier->length = 8;
	else
		specifier->length = 0;
	return (1);
}

/*
** parse_specifier doesn't validate specifier
*/

t_specifier	*parse_specifier(t_printer *printer)
{
	t_specifier		*specifier;

	specifier = ft_calloc(1, sizeof(t_specifier));
	if (!specifier)
		return (NULL);
	if (!parse_flag(specifier, printer)
		|| !parse_width(specifier, printer)
		|| !parse_precision(specifier, printer)
		|| !parse_length(specifier, printer)
		|| printer->fmt_idx >= printer->fmt_len)
	{
		free(specifier);
		return (NULL);
	}
	specifier->specifier = printer_getc(printer);
	printer_popc(printer);
	resolve_specifier(specifier);
	return (specifier);
}
