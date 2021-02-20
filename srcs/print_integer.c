/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:49:43 by jleem             #+#    #+#             */
/*   Updated: 2021/02/20 22:50:21 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"

void	print_integer(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	str = "[integer]";
	print(str, printer, specifier);
}
