/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:39:27 by jleem             #+#    #+#             */
/*   Updated: 2021/02/26 05:10:46 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "specifier.h"
#include <stdarg.h>

void	print_char(t_printer *printer, t_specifier *specifier)
{
	if (!specifier->f_minus)
		while (--specifier->width > 0)
			printer_putc(printer, ' ');
	printer_putc(printer, va_arg(*printer->ap, int));
	if (specifier->f_minus)
		while (--specifier->width > 0)
			printer_putc(printer, ' ');
}
