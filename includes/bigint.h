/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:27:45 by jleem             #+#    #+#             */
/*   Updated: 2021/05/23 21:40:45 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIGINT_H
# define BIGINT_H

typedef unsigned int	t_size;
typedef unsigned char	t_byte;

typedef struct	s_bigint
{
	t_byte		*data;
	t_size		size;
}				t_bigint;

t_bigint	*make_bigint(t_size size);
void		free_bigint(t_bigint *bigint);
void		bigint_shift_bytes(t_bigint *bigint, int bytes);
void		bigint_shift(t_bigint *bigint, t_size bits);
void		bigint_inspect_byte(t_bigint *bigint, t_size byteidx);
void		bigint_inspect(t_bigint *bigint);

#endif
