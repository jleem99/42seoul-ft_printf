/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:55:34 by jleem             #+#    #+#             */
/*   Updated: 2021/02/26 05:11:06 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include "libft.h"

static void	print_pad(int slen, t_printer *printer, t_specifier *specifier)
{
	int		padlen;

	padlen = specifier->width - slen;
	while (padlen-- > 0)
		printer_putc(printer, ' ');
}

void		print(char const *str, t_printer *printer, t_specifier *specifier)
{
	int		slen;

	slen = ft_strlen(str);
	if (!(ft_strchr("diuoxXp", specifier->specifier) &&
		specifier->f_zero && specifier->precision == -1)
			&& !specifier->f_minus)
		print_pad(slen, printer, specifier);
	while (*str)
		printer_putc(printer, *(str++));
	if (specifier->f_minus)
		print_pad(slen, printer, specifier);
}
