/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:53:43 by jleem             #+#    #+#             */
/*   Updated: 2021/02/25 19:50:21 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"

#include "libft.h"
#include <stdlib.h>
void	print_percent(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	if (!specifier->f_minus && specifier->width > 1 && specifier->f_zero)
	{
		str = malloc(specifier->width + 1); // check
		ft_memset(str, '0', specifier->width - 1);
		str[specifier->width - 1] = '%';
		str[specifier->width] = '\0';
	}
	else
		str = ft_strdup("%");
	print(str, printer, specifier);
	free(str);
}
