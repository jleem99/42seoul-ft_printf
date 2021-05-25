/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specifier.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:34:37 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 04:50:11 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPLY_SPECIFIER_H
# define APPLY_SPECIFIER_H

typedef struct s_specifier	t_specifier;

void	apply_precision_integer(char **pstr, t_specifier *specifier);

void	apply_flag_integer(char **pstr, t_specifier *specifier, int isneg);
void	apply_flag_float(char **pstr, t_specifier *specifier, int isneg);

void	apply_flag_pound(char **pstr, t_specifier *s);
void	apply_flag_plus(char **pstr);
void	apply_flag_space(char **pstr);
void	apply_flag_zero(char **pstr, t_specifier *specifier, int isneg);
void	apply_neg(char **pstr);

void	apply_flag_zero_float(char **pstr, t_specifier *specifier, int isneg);
void	add_trailing_dot(char **pstr);


#endif
