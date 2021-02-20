/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:51:17 by jleem             #+#    #+#             */
/*   Updated: 2021/02/20 22:51:31 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"

void	print_nchar(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	str = "[nchar]";
	print(str, printer, specifier);
}
