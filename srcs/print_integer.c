/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:49:43 by jleem             #+#    #+#             */
/*   Updated: 2021/02/24 23:58:04 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include "apply_specifier.h"
#include "libft.h"
#include "getarg.h"

static void	print_d(t_printer *printer, t_specifier *specifier)
{
	intmax_t	integer;
	char		*str;

	integer = getarg_integer(printer, specifier);
	if (integer > 0)
		str = ft_uimtoa_10(integer);
	else
		str = ft_uimtoa_10(-integer);
	apply_precision_integer(&str, specifier);
	apply_flag_integer(&str, specifier, integer < 0);
	print(str, printer, specifier);
	free(str);
}

static void	print_o(t_printer *printer, t_specifier *specifier)
{
	uintmax_t	integer;
	char		*str;

	integer = getarg_uinteger(printer, specifier);
	str = ft_uimtoa_8(integer);
	apply_precision_integer(&str, specifier);
	apply_flag_integer(&str, specifier, 0);
	print(str, printer, specifier);
	free(str);
}

static void	print_u(t_printer *printer, t_specifier *specifier)
{
	uintmax_t	integer;
	char		*str;

	integer = getarg_uinteger(printer, specifier);
	str = ft_uimtoa_10(integer);
	apply_precision_integer(&str, specifier);
	apply_flag_integer(&str, specifier, 0);
	print(str, printer, specifier);
	free(str);
}

static void	print_x(t_printer *printer, t_specifier *specifier)
{
	uintmax_t	integer;
	char		*str;

	integer = getarg_uinteger(printer, specifier);
	if (specifier->specifier == 'x')
		str = ft_uimtoa_16(integer, 'a');
	else
		str = ft_uimtoa_16(integer, 'A');
	apply_precision_integer(&str, specifier);
	apply_flag_integer(&str, specifier, 0);
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
