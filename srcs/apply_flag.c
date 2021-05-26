/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:35:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 21:46:20 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "apply_specifier.h"
#include "specifier.h"
#include "libft_bonus.h"

void		apply_flag_integer(char **pstr, t_specifier *specifier, int isneg)
{
	if (specifier->apply_zero)
		apply_flag_zero(pstr, specifier, isneg);
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
}

void		apply_capitalization_float(char **pstr, t_specifier *specifier)
{
	char *const	str = *pstr;
	size_t		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

void		apply_flag_float(char **pstr, t_specifier *specifier, int isneg)
{
	if (ft_strcmp(*pstr, "inf") == 0 || ft_strcmp(*pstr, "nan") == 0)
	{
		specifier->apply_pound = 0;
		specifier->apply_zero = 0;
	}
	if (specifier->apply_pound)
		add_trailing_dot(pstr);
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
		apply_capitalization_float(pstr, specifier);
}
