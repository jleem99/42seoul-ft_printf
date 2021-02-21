/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:49:43 by jleem             #+#    #+#             */
/*   Updated: 2021/02/21 08:26:30 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include "libft.h"
#include <stddef.h>

static void	print_d(t_printer *printer, t_specifier *specifier)
{
	intmax_t	integer;
	char	*str;

	if (specifier->length == 0)
		integer = va_arg(*printer->ap, int);
	else if (specifier->length == 1)
		integer = va_arg(*printer->ap , char);
	else if (specifier->length == 2)
		integer = va_arg(*printer->ap, short);
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
	str = ft_imtoa(integer);
	print(str, printer, specifier);
	free(str);
}

static void	print_o(t_printer *printer, t_specifier *specifier)
{
	
}

static void	print_u(t_printer *printer, t_specifier *specifier)
{
	
}

static void	print_x(t_printer *printer, t_specifier *specifier)
{
	
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
