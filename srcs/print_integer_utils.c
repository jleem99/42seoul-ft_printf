/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:43:49 by jleem             #+#    #+#             */
/*   Updated: 2021/02/22 03:47:58 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "libft.h"

static char	pop_digit(intmax_t *n)
{
	char	digit;

	if (*n > 0)
		digit = '0' + (*n % 10);
	else
		digit = '0' - (*n % 10);
	*n /= 10;
	return (digit);
}

// babu
	// if (n < 0)
	// 	minus = 1;
	// else
	// 	minus = 0;
// gosu
	// minus = (n < 0);

char		*ft_imtoa(intmax_t n)
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
		digits_rev[++i_rev] = pop_digit(&n);
	while (i_rev >= 0)
		digits[i++] = digits_rev[i_rev--];
	digits[i] = '\0';
	if (minus)
		return (ft_strjoin("-", digits));
	else
		return (ft_strdup(digits));
}
