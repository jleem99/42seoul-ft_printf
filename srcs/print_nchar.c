/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:51:17 by jleem             #+#    #+#             */
/*   Updated: 2021/05/18 18:43:56 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printer.h"
#include "specifier.h"
#include <stdarg.h>

void	print_nchar(t_printer *printer, t_specifier *specifier)
{
	int		*nchar;

	nchar = va_arg(*printer->ap, int *);
	*nchar = printer->nchar;
}
