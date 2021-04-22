/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:35:46 by jleem             #+#    #+#             */
/*   Updated: 2021/03/24 13:57:53 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "apply_specifier.h"
#include "specifier.h"
#include "libft_bonus.h"

static void	apply_flag_pound(char **pstr, t_specifier *s)
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

static void	apply_flag_plus(char **pstr)
{
	char	*str_new;

	str_new = ft_strjoin("+", *pstr);
	free(*pstr);
	*pstr = str_new;
}

static void	apply_flag_space(char **pstr)
{
	char	*str_new;

	str_new = ft_strjoin(" ", *pstr);
	free(*pstr);
	*pstr = str_new;
}

static void	apply_flag_zero(char **pstr, t_specifier *specifier, int isneg)
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

static void	apply_neg(char **pstr)
{
	char	*str_new;

	str_new = ft_strjoin("-", *pstr);
	free(*pstr);
	*pstr = str_new;
}

void		apply_flag_integer(char **pstr, t_specifier *specifier, int isneg)
{
	if (specifier->f_zero && specifier->precision == -1 && !specifier->f_minus)
		apply_flag_zero(pstr, specifier, isneg);
	if (isneg)
		apply_neg(pstr);
	else if (ft_strchr("oxXp", specifier->specifier) && specifier->f_pound)
		apply_flag_pound(pstr, specifier);
	else
	{
		if (specifier->f_plus)
			apply_flag_plus(pstr);
		else if (specifier->f_space)
			apply_flag_space(pstr);
	}
}
