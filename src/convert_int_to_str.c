/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:43:49 by jleem             #+#    #+#             */
/*   Updated: 2021/07/08 17:51:45 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft.h"

char	*uintmax_to_str_10(uintmax_t n)
{
	char		digits[40];
	char		digits_rev[39];
	int			i;
	int			i_rev;

	i = 0;
	i_rev = -1;
	while (n != 0)
	{
		digits_rev[++i_rev] = '0' + (n % 10);
		n /= 10;
	}
	while (i_rev >= 0)
		digits[i++] = digits_rev[i_rev--];
	digits[i] = '\0';
	return (ft_strdup(digits));
}

char	*uintmax_to_str_8(uintmax_t n)
{
	char		digits[44];
	char		digits_rev[43];
	int			i;
	int			i_rev;

	i = 0;
	i_rev = -1;
	while (n != 0)
	{
		digits_rev[++i_rev] = '0' + (n % 8);
		n /= 8;
	}
	while (i_rev >= 0)
		digits[i++] = digits_rev[i_rev--];
	digits[i] = '\0';
	return (ft_strdup(digits));
}

char	*uintmax_to_str_16(uintmax_t n, char base)
{
	char		digits[33];
	char		digits_rev[32];
	int			i;
	int			i_rev;

	i = 0;
	i_rev = -1;
	while (n != 0)
	{
		if (n % 16 < 10)
			digits_rev[++i_rev] = '0' + (n % 16);
		else
			digits_rev[++i_rev] = base + (n % 16 - 10);
		n /= 16;
	}
	while (i_rev >= 0)
		digits[i++] = digits_rev[i_rev--];
	digits[i] = '\0';
	return (ft_strdup(digits));
}
