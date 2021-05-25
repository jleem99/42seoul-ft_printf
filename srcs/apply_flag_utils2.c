/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dher <dher@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:49:23 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 05:27:24 by dher             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "apply_specifier.h"
#include "specifier.h"
#include "libft_bonus.h"

void	apply_flag_zero_float(char **pstr, t_specifier *specifier, int isneg)
{
	char		*str_new;
	int const	slen = ft_strlen(*pstr);
	int			padlen;

	padlen = specifier->width - slen;
	if (isneg)
		padlen -= 1;
	else
	{
		if (specifier->f_plus || specifier->f_space)
			padlen -= 1;
	}
	if (padlen <= 0)
		return ;
	str_new = malloc(padlen + slen + 1); // malloc check ctrl f malloc
	ft_memset(str_new, '0', padlen);
	ft_strcpy(str_new + padlen, *pstr);
	free(*pstr);
	*pstr = str_new;
}

void	add_trailing_dot(char **pstr)
{
	char	*str_new;

	str_new = ft_strjoin(*pstr, ".");
	free(*pstr);
	*pstr = str_new;
}
