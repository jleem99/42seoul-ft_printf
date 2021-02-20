/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:50:58 by jleem             #+#    #+#             */
/*   Updated: 2021/02/20 22:51:07 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"

void	print_ptr(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	str = "[ptr]";
	print(str, printer, specifier);
}
