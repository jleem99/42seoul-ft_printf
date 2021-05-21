/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:15:56 by jleem             #+#    #+#             */
/*   Updated: 2021/05/21 23:19:11 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H

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
	char		f_minus;
	char		f_plus;
	char		f_space;
	char		f_pound;
	char		f_zero;
	char		apply_pound;
	char		apply_zero;
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
