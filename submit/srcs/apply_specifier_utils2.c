/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specifier_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:49:23 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 23:31:04 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "apply_specifier.h"
#include "specifier.h"
#include "libft_bonus.h"

void	apply_neg(char **pstr)
{
	char	*str_new;

	str_new = ft_strjoin("-", *pstr);
	free(*pstr);
	*pstr = str_new;
}

void	apply_capitalization(char **pstr)
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
