/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:06:05 by jleem             #+#    #+#             */
/*   Updated: 2021/05/21 15:58:51 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include "libft_bonus.h"
#include <stdlib.h>

void		apply_precision_integer(char **pstr, t_specifier *specifier)
{
	char		*str_new;
	int const	slen = ft_strlen(*pstr);

	if (slen == 0 && specifier->precision == -1)
	{
		free(*pstr);
		*pstr = ft_strdup("0"); // malloc check
	}
	else if (specifier->precision > slen)
	{
		str_new = malloc(specifier->precision + 1); // malloc check ctrl f malloc
		ft_memset(str_new, '0', specifier->precision - slen);
		ft_strcpy(str_new + specifier->precision - slen, *pstr);
		free(*pstr);
		*pstr = str_new;
	}
}
