/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specifier_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 23:43:58 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 23:19:03 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include "libft_bonus.h"

void	apply_flag_pound(char **pstr, t_specifier *specifier)
{
	char	*str_new;

	if (specifier->specifier == 'o')
		str_new = ft_strjoin("0", *pstr);
	else if (specifier->specifier == 'x' || specifier->specifier == 'p')
		str_new = ft_strjoin("0x", *pstr);
	else if (specifier->specifier == 'X')
		str_new = ft_strjoin("0X", *pstr);
	else if (is_float(specifier))
		str_new = ft_strjoin(*pstr, ".");
	else
		return ;
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

void	apply_flag_zero_integer(char **pstr, t_specifier *specifier, int isneg)
{
	char		*str_new;
	int const	slen = ft_strlen(*pstr);
	int			padlen;

	padlen = specifier->width - slen;
	if (isneg)
		padlen -= 1;
	else
	{
		if (specifier->apply_pound)
		{
			if (specifier->specifier == 'o')
				padlen -= 1;
			else
				padlen -= 2;
		}
		else if (specifier->f_plus || specifier->f_space)
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
