/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:09:36 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 22:44:41 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include <stdlib.h>

char		*bigint_to_string(t_bigint *bigint)
{
	char *const	string = malloc(bigint->size + 1);
	size_t		byteidx;

	byteidx = 0;
	while (byteidx < bigint->size)
	{
		string[bigint->size - 1 - byteidx] = '0' + bigint->data[byteidx];
		byteidx++;
	}
	string[byteidx] = '\0';
	return (string);
}

char		*bigint_to_string_hex(t_bigint *bigint, char base)
{
	char *const	string = malloc(bigint->size + 1);
	uint8_t		byte;
	size_t		byteidx;

	byteidx = 0;
	while (byteidx < bigint->size)
	{
		byte = bigint->data[byteidx];
		if (byte < 10)
			string[bigint->size - 1 - byteidx] = '0' + byte;
		else
			string[bigint->size - 1 - byteidx] = base + (byte - 10);
		byteidx++;
	}
	string[byteidx] = '\0';
	return (string);
}
