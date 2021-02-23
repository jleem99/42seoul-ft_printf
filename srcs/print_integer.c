/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:49:43 by jleem             #+#    #+#             */
/*   Updated: 2021/02/22 17:19:17 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include "flag.h"
#include "libft.h"
#include <stddef.h>
#include <stdarg.h>

static void	print_d(t_printer *printer, t_specifier *specifier)
{
	intmax_t	integer;
	char		*str;

	if (specifier->length < 3)
		integer = va_arg(*printer->ap, int);
	else if (specifier->length == 3)
		integer = va_arg(*printer->ap, long);
	else if (specifier->length == 4)
		integer = va_arg(*printer->ap, long long);
	else if (specifier->length == 5)
		integer = va_arg(*printer->ap, intmax_t);
	else if (specifier->length == 6)
		integer = va_arg(*printer->ap, size_t);
	else if (specifier->length == 7)
		integer = va_arg(*printer->ap, ptrdiff_t);
	else
		return ;
	str = ft_imtoa_10(integer);
	apply_flag_integer(&str, specifier, integer > 0);
	print(str, printer, specifier);
	free(str);
}

static void	print_o(t_printer *printer, t_specifier *specifier)
{
	uintmax_t	integer;
	char		*str;

	if (specifier->length < 3)
		integer = va_arg(*printer->ap, unsigned int);
	else if (specifier->length == 3)
		integer = va_arg(*printer->ap, unsigned long);
	else if (specifier->length == 4)
		integer = va_arg(*printer->ap, unsigned long long);
	else if (specifier->length == 5)
		integer = va_arg(*printer->ap, uintmax_t);
	else if (specifier->length == 6)
		integer = va_arg(*printer->ap, size_t);
	else if (specifier->length == 7)
		integer = va_arg(*printer->ap, ptrdiff_t);
	else
		return ;
	str = ft_uimtoa_8(integer);
	apply_flag_integer(&str, specifier, 1);
	print(str, printer, specifier);
	free(str);
}

static void	print_u(t_printer *printer, t_specifier *specifier)
{
	uintmax_t	integer;
	char		*str;

	if (specifier->length < 3)
		integer = va_arg(*printer->ap, unsigned int);
	else if (specifier->length == 3)
		integer = va_arg(*printer->ap, unsigned long);
	else if (specifier->length == 4)
		integer = va_arg(*printer->ap, unsigned long long);
	else if (specifier->length == 5)
		integer = va_arg(*printer->ap, uintmax_t);
	else if (specifier->length == 6)
		integer = va_arg(*printer->ap, size_t);
	else if (specifier->length == 7)
		integer = va_arg(*printer->ap, ptrdiff_t);
	else
		return ;
	str = ft_uimtoa_10(integer);
	apply_flag_integer(&str, specifier, 1);
	print(str, printer, specifier);
	free(str);
}

static void	print_x(t_printer *printer, t_specifier *specifier)
{
	uintmax_t	integer;
	char		*str;

	if (specifier->length < 3)
		integer = va_arg(*printer->ap, unsigned int);
	else if (specifier->length == 3)
		integer = va_arg(*printer->ap, unsigned long);
	else if (specifier->length == 4)
		integer = va_arg(*printer->ap, unsigned long long);
	else if (specifier->length == 5)
		integer = va_arg(*printer->ap, uintmax_t);
	else if (specifier->length == 6)
		integer = va_arg(*printer->ap, size_t);
	else if (specifier->length == 7)
		integer = va_arg(*printer->ap, ptrdiff_t);
	else
		return ;
	if (specifier->specifier == 'x')
		str = ft_uimtoa_16(integer, 'a');
	else
		str = ft_uimtoa_16(integer, 'A');
	apply_flag_integer(&str, specifier, 1);
	print(str, printer, specifier);
	free(str);
}

void		print_integer(t_printer *printer, t_specifier *specifier) // validate malloc
{
	if (specifier->specifier == 'd' || specifier->specifier == 'i')
		print_d(printer, specifier);
	else if (specifier->specifier == 'u')
		print_u(printer, specifier);
	else if (specifier->specifier == 'o')
		print_o(printer, specifier);
	else if (specifier->specifier == 'x' || specifier->specifier == 'X')
		print_x(printer, specifier);
}
