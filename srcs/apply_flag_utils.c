/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:43:58 by jleem             #+#    #+#             */
/*   Updated: 2021/05/21 16:09:38 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include "libft_bonus.h"

void	apply_flag_pound(char **pstr, t_specifier *s)
{
	char	*str_new;

	if (s->specifier == 'o')
		str_new = ft_strjoin("0", *pstr);
	else if (s->specifier == 'x' || s->specifier == 'p')
		str_new = ft_strjoin("0x", *pstr);
	else if (s->specifier == 'X')
		str_new = ft_strjoin("0X", *pstr);
	free(*pstr);
	*pstr = str_new;
}

void	apply_flag_plus(char **pstr)
{
	char	*str_new;

	str_new = ft_strjoin("+", *pstr);
	free(*pstr);
	*pstr = str_new;
}

void	apply_flag_space(char **pstr)
{
	char	*str_new;

	str_new = ft_strjoin(" ", *pstr);
	free(*pstr);
	*pstr = str_new;
}

void	apply_flag_zero(char **pstr, t_specifier *specifier, int isneg)
{
	char		*str_new;
	int const	slen = ft_strlen(*pstr);
	int			padlen;

	padlen = specifier->width - slen;
	if (ft_strchr("oxXp", specifier->specifier) && specifier->f_pound)
	{
		if (specifier->specifier == 'o')
			padlen -= 1;
		else
			padlen -= 2;
	}
	else if (specifier->f_plus || specifier->f_space)
		padlen -= 1;
	if (isneg)
		padlen -= 1;
	if (padlen <= 0)
		return ;
	str_new = malloc(padlen + slen + 1); // malloc check ctrl f malloc
	ft_memset(str_new, '0', padlen);
	ft_strcpy(str_new + padlen, *pstr);
	free(*pstr);
	*pstr = str_new;
}

void	apply_neg(char **pstr)
{
	char	*str_new;

	str_new = ft_strjoin("-", *pstr);
	free(*pstr);
	*pstr = str_new;
}
