/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:55:34 by jleem             #+#    #+#             */
/*   Updated: 2021/05/21 04:01:43 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include "libft.h"

void	print(char const *str, t_printer *printer, t_specifier *specifier)
{
	int const	slen = ft_strlen(str);

	print_pad_left(slen, printer, specifier);
	while (*str)
		printer_putc(printer, *(str++));
	print_pad_right(slen, printer, specifier);
}

void	print_pad_left(int slen, t_printer *printer, t_specifier *specifier)
{
	if (!((is_integer(specifier) || specifier->specifier == 'p') && specifier->apply_zero))
		print_pad(slen, printer, specifier);
}

void	print_pad_right(int slen, t_printer *printer, t_specifier *specifier)
{
	if (specifier->f_minus)
		print_pad(slen, printer, specifier);
}

void	print_pad(int slen, t_printer *printer, t_specifier *specifier)
{
	int		padlen;

	padlen = specifier->width - slen;
	while (padlen-- > 0)
		printer_putc(printer, ' ');
}
