/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:01 by jleem             #+#    #+#             */
/*   Updated: 2021/01/12 00:40:37 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long long	num;
	char		digits[11];
	char		digits_rev[10];
	int			digit_index;
	int			i;

	if (n == 0)
		return (ft_strdup("0"));
	num = n;
	if (n < 0)
		num *= -1;
	digit_index = -1;
	while (num != 0)
	{
		digits_rev[++digit_index] = "0123456789"[num % 10];
		num /= 10;
	}
	i = 0;
	while (digit_index >= 0)
		digits[i++] = digits_rev[digit_index--];
	digits[i] = '\0';
	return (n < 0 ? ft_strjoin("-", digits) : ft_strdup(digits));
}
