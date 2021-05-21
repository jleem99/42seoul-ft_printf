/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:55:34 by jleem             #+#    #+#             */
/*   Updated: 2021/05/21 21:51:55 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include "libft.h"

void	print(char const *str, t_printer *printer, t_specifier *specifier)
{
	int const	slen = ft_strlen(str);

	if (!specifier->f_minus && !specifier->apply_zero)
		print_pad(slen, printer, specifier);
	while (*str)
		printer_putc(printer, *(str++));
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
