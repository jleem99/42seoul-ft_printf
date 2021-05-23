/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:50:40 by jleem             #+#    #+#             */
/*   Updated: 2021/05/23 03:43:33 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include "libft.h"
#include <stdlib.h>

#include "getarg.h"
#include "float_to_str.h"

static void	print_f(t_printer *printer, t_specifier *specifier)
{
	long double	flt = getarg_float(printer, specifier);
	char		*str;

	if (specifier->precision == -1)
		str = long_double_to_str_10(flt, 6);
	else
		str = long_double_to_str_10(flt, specifier->precision);
	
	// apply_flag_float(&str, specifier, ...);
	print(str, printer, specifier);
	free(str);
}

void	print_float(t_printer *printer, t_specifier *specifier) // validate malloc
{
	if (specifier->specifier == 'f' || specifier->specifier == 'F')
		print_f(printer, specifier);
	// else if (specifier->specifier == 'e' || specifier->specifier == 'E')
	// 	print_e(printer, specifier);
	// else if (specifier->specifier == 'g' || specifier->specifier == 'G')
	// 	print_g(printer, specifier);
	// else if (specifier->specifier == 'a' || specifier->specifier == 'A')
	// 	print_a(printer, specifier);
}
