/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:50:40 by jleem             #+#    #+#             */
/*   Updated: 2021/07/08 17:54:19 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include "apply_specifier.h"
#include "getarg.h"
#include "convert.h"
#include <stdlib.h>

static void	print_f(t_printer *printer, t_specifier *specifier)
{
	long double const	flt = getarg_float(printer, specifier);
	t_ieee854 const		ieee854 = {flt};
	char				*str;

	str = long_double_to_str(ieee854, specifier);
	apply_flag_float(&str, specifier, ieee854_is_negative(ieee854));
	print(str, printer, specifier);
	free(str);
}

static void	print_e(t_printer *printer, t_specifier *specifier)
{
	long double const	flt = getarg_float(printer, specifier);
	t_ieee854 const		ieee854 = {flt};
	char				*str;

	str = long_double_to_str(ieee854, specifier);
	apply_flag_float(&str, specifier, ieee854_is_negative(ieee854));
	print(str, printer, specifier);
	free(str);
}

void	print_float(t_printer *printer, t_specifier *specifier)
{
	if (specifier->specifier == 'f' || specifier->specifier == 'F')
		print_f(printer, specifier);
	else if (specifier->specifier == 'e' || specifier->specifier == 'E')
		print_e(printer, specifier);
}
