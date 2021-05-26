/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:35:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 10:44:29 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "apply_specifier.h"
#include "specifier.h"
#include "libft.h"

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

void		apply_flag_float(char **pstr, t_specifier *specifier, int isneg)
{
	if (ft_strncmp(*pstr, "inf", 3) == 0 || ft_strncmp(*pstr, "nan", 3) == 0)
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
	else
	{
		if (specifier->f_plus)
			apply_flag_plus(pstr);
		else if (specifier->f_space)
			apply_flag_space(pstr);
	}
}
