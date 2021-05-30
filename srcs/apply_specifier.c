/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:35:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 04:34:18 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "apply_specifier.h"
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

void		apply_flag_integer(char **pstr, t_specifier *specifier, int isneg)
{
	if (specifier->apply_zero)
		apply_flag_zero_integer(pstr, specifier, isneg);
	if (isneg)
		apply_neg(pstr);
	else
	{
		if (specifier->apply_pound)
			apply_flag_pound(pstr, specifier);
		else if (specifier->f_plus)
			apply_flag_plus(pstr);
		else if (specifier->f_space)
			apply_flag_space(pstr);
	}
	// if (is_integer_capital(specifier))
	// 	apply_capitalization(pstr);
}

void		apply_flag_float(char **pstr, t_specifier *specifier, int isneg)
{
	if (ft_strcmp(*pstr, "inf") == 0 || ft_strcmp(*pstr, "nan") == 0)
	{
		specifier->apply_pound = 0;
		specifier->apply_zero = 0;
	}
	if (ft_strchr("eE", specifier->specifier)) // handle for g situation)
		specifier->apply_pound = 0;
	if (specifier->apply_pound)
		apply_flag_pound(pstr, specifier);
	if (specifier->apply_zero)
		apply_flag_zero_float(pstr, specifier, isneg);
	if (isneg)
		apply_neg(pstr);
	else if (ft_strcmp(*pstr, "nan") != 0)
	{
		if (specifier->f_plus)
			apply_flag_plus(pstr);
		else if (specifier->f_space)
			apply_flag_space(pstr);
	}
	if (is_float_capital(specifier))
		apply_capitalization(pstr);
}
