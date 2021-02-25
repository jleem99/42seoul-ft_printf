/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:48:23 by jleem             #+#    #+#             */
/*   Updated: 2021/02/25 01:36:57 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"
#include "libft.h"

void	print_str(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	str = va_arg(*printer->ap, char *);
	if (!str)
		str = "(null)";
	if (specifier->precision != -1)
	{
		str = ft_substr(str, 0, specifier->precision);
		print(str, printer, specifier);
		free(str);
	}
	else
		print(str, printer, specifier);
}
