/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 22:03:26 by jleem             #+#    #+#             */
/*   Updated: 2021/07/08 17:53:20 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include "libft.h"

void	resolve_specifier(t_specifier *specifier)
{
	if (is_integer(specifier))
	{
		specifier->apply_zero = specifier->f_zero
			&& specifier->precision == -1 && !specifier->f_minus;
		specifier->apply_pound = ft_strchr("oxXp", specifier->specifier)
			&& specifier->f_pound;
	}
	else if (is_float(specifier))
	{
		specifier->apply_zero = specifier->f_zero
			&& !specifier->f_minus;
	}
}

int	is_specifier(t_specifier *specifier)
{
	return (ft_strchr("diuoxXfFeEgGaAcspn%", specifier->specifier) != NULL);
}

int	is_integer(t_specifier *specifier)
{
	return (ft_strchr("diuoxX", specifier->specifier) != NULL);
}

int	is_float(t_specifier *specifier)
{
	return (ft_strchr("fFeEgGaA", specifier->specifier) != NULL);
}

int	is_float_capital(t_specifier *specifier)
{
	return (ft_strchr("FEGA", specifier->specifier) != NULL);
}
