/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:48:23 by jleem             #+#    #+#             */
/*   Updated: 2021/02/20 22:49:14 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"

void	print_str(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	str = va_arg(*printer->ap, char *);
	print(str, printer, specifier);
}
