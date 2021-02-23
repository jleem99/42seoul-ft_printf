/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:50:40 by jleem             #+#    #+#             */
/*   Updated: 2021/02/22 17:47:45 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include <stdarg.h>

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	*ft_revsearch(char const *s, int c)
{
	while (*s != c)
		s--;
	return (s);
}

static void	print_f(t_printer *printer, t_specifier *specifier)
{
	char	*str;

	str = malloc(100);
	char	*curfmt = printer->fmt + printer->fmt_idx;
	char	*curfmt_start = ft_revsearch(curfmt, '%');
	char	*fmt = ft_substr(curfmt_start, 0, curfmt - curfmt_start);
	if (specifier->length == 8)
	{
		sprintf(str, fmt, va_arg(*printer->ap, long double));
	}
	else
	{
		sprintf(str, fmt, va_arg(*printer->ap, double));
	}
	// apply_flag_float(&str, specifier, ...);
	print(str, printer, specifier);
	free(str);
}

static void	print_e(t_printer *printer, t_specifier *specifier)
{
	char	*str;

	str = malloc(100);
	char	*curfmt = printer->fmt + printer->fmt_idx;
	char	*curfmt_start = ft_revsearch(curfmt, '%');
	char	*fmt = ft_substr(curfmt_start, 0, curfmt - curfmt_start);
	if (specifier->length == 8)
	{
		sprintf(str, fmt, va_arg(*printer->ap, long double));
	}
	else
	{
		sprintf(str, fmt, va_arg(*printer->ap, double));
	}
	// apply_flag_float(&str, specifier, ...);
	print(str, printer, specifier);
	free(str);
}

static void	print_g(t_printer *printer, t_specifier *specifier)
{
	char	*str;

	str = malloc(100);
	char	*curfmt = printer->fmt + printer->fmt_idx;
	char	*curfmt_start = ft_revsearch(curfmt, '%');
	char	*fmt = ft_substr(curfmt_start, 0, curfmt - curfmt_start);
	if (specifier->length == 8)
	{
		sprintf(str, fmt, va_arg(*printer->ap, long double));
	}
	else
	{
		sprintf(str, fmt, va_arg(*printer->ap, double));
	}
	// apply_flag_float(&str, specifier, ...);
	print(str, printer, specifier);
	free(str);
}

static void	print_a(t_printer *printer, t_specifier *specifier)
{
	char	*str;

	str = malloc(100);
	char	*curfmt = printer->fmt + printer->fmt_idx;
	char	*curfmt_start = ft_revsearch(curfmt, '%');
	char	*fmt = ft_substr(curfmt_start, 0, curfmt - curfmt_start);
	if (specifier->length == 8)
	{
		sprintf(str, fmt, va_arg(*printer->ap, long double));
	}
	else
	{
		sprintf(str, fmt, va_arg(*printer->ap, double));
	}
	// apply_flag_float(&str, specifier, ...);
	print(str, printer, specifier);
	free(str);
}

void	print_float(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	if (specifier->specifier == 'f' || specifier->specifier == 'F')
		print_f(printer, specifier);
	else if (specifier->specifier == 'e' || specifier->specifier == 'E')
		print_e(printer, specifier);
	else if (specifier->specifier == 'g' || specifier->specifier == 'G')
		print_g(printer, specifier);
	else if (specifier->specifier == 'a' || specifier->specifier == 'A')
		print_a(printer, specifier);
}
