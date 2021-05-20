/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:35:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/21 04:05:02 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "apply_specifier.h"
#include "specifier.h"
#include "libft.h"

void	apply_flag_integer(char **pstr, t_specifier *specifier, int isneg)
{
	if (specifier->apply_zero)
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
