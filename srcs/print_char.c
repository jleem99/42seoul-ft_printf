/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:39:27 by jleem             #+#    #+#             */
/*   Updated: 2021/02/22 02:53:12 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include <stdarg.h>
#include <stdlib.h>

void	print_char(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	str = malloc(2);
	str[0] = va_arg(*printer->ap, int);
	str[1] = '\0';
	print(str, printer, specifier);
	free(str);
}
