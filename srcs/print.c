/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 21:55:34 by jleem             #+#    #+#             */
/*   Updated: 2021/02/21 03:18:12 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include "libft.h"

static void	print_lpad(int slen, t_printer *printer, t_specifier *specifier)
{
	char	pad;
	int		padlen;
	int		i;

	if (specifier->f_minus)
		return ;
	padlen = specifier->width - slen;
	if (padlen > 0)
	{
		if (specifier->f_zero)
			pad = '0';
		else
			pad = ' ';
		i = 0;
		while (i++ < padlen)
			ft_putchar_fd(pad, 1);
	}
}

static void	print_rpad(int slen, t_printer *printer, t_specifier *specifier)
{
	int		padlen;
	int		i;

	if (!specifier->f_minus)
		return ;
	padlen = specifier->width - slen;
	if (padlen > 0)
	{
		i = 0;
		while (i++ < padlen)
			ft_putchar_fd(' ', 1);
	}
}

void		print(char const *str, t_printer *printer, t_specifier *specifier)
{
	int		slen;

	slen = ft_strlen(str);
	print_lpad(slen, printer, specifier);
	while (*str)
		printer_putc(printer, *(str++));
	print_rpad(slen, printer, specifier);
}
