/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:50:58 by jleem             #+#    #+#             */
/*   Updated: 2021/02/22 17:55:15 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"

void	print_ptr(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;
	void	*ptr;

	ptr = va_arg(*printer->ap, void *);
	if (ptr)
	{
		str = ft_uimtoa_16(ptr, 'a');
		specifier->f_pound = 1;
		apply_flag_integer(&str, specifier, 1);
		print(str, printer, specifier);
		free(str);
	}
	else
	{
		print("(nil)", printer, specifier);
	}
}
