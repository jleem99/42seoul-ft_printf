/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:43:49 by jleem             #+#    #+#             */
/*   Updated: 2021/02/22 17:02:34 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"

char		*ft_imtoa_10(intmax_t n)
{
	char		digits[40];
	char		digits_rev[39];
	int			i;
	int			i_rev;
	int const	minus = (n < 0);

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	i_rev = -1;
	while (n != 0)
	{
		if (minus)
			digits_rev[++i_rev] = '0' - (n % 10);
		else
			digits_rev[++i_rev] = '0' + (n % 10);
		n /= 10;
	}
	while (i_rev >= 0)
		digits[i++] = digits_rev[i_rev--];
	digits[i] = '\0';
	if (minus)
		return (ft_strjoin("-", digits));
	else
		return (ft_strdup(digits));
}

char		*ft_imtoa_8(intmax_t n)
{
	char		digits[44];
	char		digits_rev[43];
	int			i;
	int			i_rev;
	int const	minus = (n < 0);

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	i_rev = -1;
	while (n != 0)
	{
		if (minus)
			digits_rev[++i_rev] = '0' - (n % 8);
		else
			digits_rev[++i_rev] = '0' + (n % 8);
		n /= 8;
	}
	while (i_rev >= 0)
		digits[i++] = digits_rev[i_rev--];
	digits[i] = '\0';
	if (minus)
		return (ft_strjoin("-", digits));
	else
		return (ft_strdup(digits));
}

char		*ft_imtoa_16(intmax_t n, char base)
{
	char		digits[33];
	char		digits_rev[32];
	int			i;
	int			i_rev;
	int const	minus = (n < 0);

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	i_rev = -1;
	while (n != 0)
	{
		if (minus)
		{
			if (n % 16 < 10)
				digits_rev[++i_rev] = '0' - (n % 16);
			else
				digits_rev[++i_rev] = base - (n % 16 - 10);
		}
		else
		{
			if (n % 16 < 10)
				digits_rev[++i_rev] = '0' + (n % 16);
			else
				digits_rev[++i_rev] = base + (n % 16 - 10);
		}
		n /= 16;
	}
	while (i_rev >= 0)
		digits[i++] = digits_rev[i_rev--];
	digits[i] = '\0';
	if (minus)
		return (ft_strjoin("-", digits));
	else
		return (ft_strdup(digits));
}
