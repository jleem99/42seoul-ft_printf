/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:35:46 by jleem             #+#    #+#             */
/*   Updated: 2021/02/23 19:11:26 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "apply_flag.h"
#include "specifier.h"
#include "libft.h"

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

void		apply_flag_integer(char **pstr, t_specifier *s, int plus)
{
	if (s->f_pound)
		apply_flag_pound(pstr, s);
	if (plus)
	{
		if (s->f_plus)
			apply_flag_plus(pstr);
		else if (s->f_space)
			apply_flag_space(pstr);
	}
}
