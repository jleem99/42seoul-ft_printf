/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:15:56 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 21:27:40 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H

# include <stdint.h>

typedef struct s_printer	t_printer;

/*
**	[struct s_specifier]
**		Contains information of a format specifier
**
**		A format specifier has following prototype
**			%[flags][width][.precision][length]specifier
**
**	[member variables]
**		length: specifies data type of argument
**			0	none
**			1	hh
**			2	h
**			3	l
**			4	ll
**			5	j
**			6	z
**			7	t
**			8	L
*/

typedef struct	s_specifier
{
	char		specifier;
	uint8_t		f_minus		: 1;
	uint8_t		f_plus		: 1;
	uint8_t		f_space		: 1;
	uint8_t		f_pound		: 1;
	uint8_t		f_zero		: 1;
	uint8_t		apply_pound	: 1;
	uint8_t		apply_zero	: 1;
	int			width;
	int			precision;
	int			length;
}				t_specifier;

t_specifier		*parse_specifier(t_printer *printer);

/*
** Utility Functions
*/
void			resolve_specifier(t_specifier *specifier);
int				is_specifier(t_specifier *specifier);
int				is_integer(t_specifier *specifier);
int				is_float(t_specifier *specifier);

#endif
