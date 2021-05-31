/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_inspect_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 03:44:42 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 22:49:29 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void		bigint_inspect_byte(t_bigint const *bigint, size_t byteidx)
{
	int		bitmask;
	int		bit;

	bitmask = 0b10000000;
	while (bitmask != 0)
	{
		bit = (bigint->data[byteidx] & bitmask) != 0;
		ft_putchar_fd(bit + '0', 1);
		bitmask >>= 1;
	}
}

void		bigint_inspect_byte_decimal(t_bigint const *bigint, size_t byteidx)
{
	ft_putchar_fd('0' + bigint->data[byteidx], 1);
}

void		bigint_inspect(t_bigint const *bigint)
{
	size_t	i;

	i = 0;
	while (i < bigint->size)
	{
		if (i % 4 == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(' ', 1);
		bigint_inspect_byte(bigint, (bigint->size - 1 - i));
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void		bigint_inspect_decimal(t_bigint const *bigint)
{
	size_t	i;

	i = 0;
	while (i < bigint->size)
	{
		if (i % 8 == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(' ', 1);
		bigint_inspect_byte_decimal(bigint, (bigint->size - 1 - i));
		i++;
	}
	ft_putchar_fd('\n', 1);
}
