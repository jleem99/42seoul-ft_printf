/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:24:58 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 14:35:59 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getarg.h"
#include "printer.h"
#include "specifier.h"
#include <stdarg.h>

intmax_t	getarg_integer(t_printer *printer, t_specifier *specifier)
{
	if (specifier->length < 3)
		return (va_arg(*printer->ap, int));
	else if (specifier->length == 3)
		return (va_arg(*printer->ap, long));
	else if (specifier->length == 4)
		return (va_arg(*printer->ap, long long));
	else if (specifier->length == 5)
		return (va_arg(*printer->ap, intmax_t));
	else if (specifier->length == 6)
		return (va_arg(*printer->ap, size_t));
	else if (specifier->length == 7)
		return (va_arg(*printer->ap, ptrdiff_t));
	else
		return (va_arg(*printer->ap, int));
}

uintmax_t	getarg_uinteger(t_printer *printer, t_specifier *specifier)
{
	if (specifier->length == 0)
		return (va_arg(*printer->ap, unsigned int));
	else if (specifier->length == 1)
		return ((unsigned char)va_arg(*printer->ap, unsigned int));
	else if (specifier->length == 2)
		return ((unsigned short)va_arg(*printer->ap, unsigned int));
	else if (specifier->length == 3)
		return (va_arg(*printer->ap, unsigned long));
	else if (specifier->length == 4)
		return (va_arg(*printer->ap, unsigned long long));
	else if (specifier->length == 5)
		return (va_arg(*printer->ap, uintmax_t));
	else if (specifier->length == 6)
		return (va_arg(*printer->ap, size_t));
	else if (specifier->length == 7)
		return (va_arg(*printer->ap, ptrdiff_t));
	else
		return (va_arg(*printer->ap, unsigned int));
}

long double	getarg_float(t_printer *printer, t_specifier *specifier)
{
	if (specifier->length < 8)
		return (va_arg(*printer->ap, double));
	else
		return (va_arg(*printer->ap, long double));
}
