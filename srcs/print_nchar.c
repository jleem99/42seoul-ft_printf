/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:51:17 by jleem             #+#    #+#             */
/*   Updated: 2021/02/21 03:26:51 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include <stdarg.h>

void	print_nchar(t_printer *printer, t_specifier *specifier) // validate malloc
{
	int		*nchar;

	nchar = va_arg(*printer->ap, int *);
	*nchar = printer->nchar;
}
