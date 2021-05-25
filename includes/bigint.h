/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:27:45 by jleem             #+#    #+#             */
/*   Updated: 2021/05/25 17:05:24 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
# define BIGINT_H

# include <stddef.h>
# include <stdint.h>

typedef struct	s_bigint
{
	uint8_t		*data;
	uint8_t		base;
	size_t		size;
}				t_bigint;

t_bigint	*make_bigint(size_t size);
void		free_bigint(t_bigint *bigint);
void		bigint_resize(t_bigint *bigint, size_t new_size);
void		bigint_set_value(t_bigint *bigint, uint64_t value);
void		bigint_set_digit(t_bigint *bigint, uint16_t value, size_t byteidx);

void		bigint_add(t_bigint *bigint, t_bigint *addend);
void		bigint_add_with_index(t_bigint *bigint, uint8_t addend, size_t byteidx);
void		bigint_multiply(t_bigint *bigint, uint8_t multiplier);

void		bigint_shift_bytes(t_bigint *bigint, int bytes);
void		bigint_shift(t_bigint *bigint, size_t bits);

void		bigint_inspect_byte(t_bigint const *bigint, size_t byteidx);
void		bigint_inspect_byte_decimal(t_bigint const *bigint, size_t byteidx);
void		bigint_inspect(t_bigint const *bigint);
void		bigint_inspect_decimal(t_bigint const *bigint);

#endif
