/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:06:05 by jleem             #+#    #+#             */
/*   Updated: 2021/02/24 12:50:28 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include "libft_bonus.h"
#include <stdlib.h>

void		apply_precision_integer(char **pstr, t_specifier *specifier)
{
	char	*str_new;

	if (**pstr == '\0' && specifier->precision == -1)
		specifier->precision = 1;
	if (specifier->precision <= (int)ft_strlen(*pstr))
		return ;
	else
	{
		str_new = malloc(specifier->precision + 1); // malloc check ctrl f malloc
		ft_memset(str_new, '0', specifier->precision - ft_strlen(*pstr));
		ft_strcpy(str_new + specifier->precision - ft_strlen(*pstr), *pstr);
	}
	free(*pstr);
	*pstr = str_new;
}
