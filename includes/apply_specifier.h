/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specifier.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 04:34:37 by jleem             #+#    #+#             */
/*   Updated: 2021/02/24 13:04:22 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

typedef struct s_specifier	t_specifier;

void	apply_flag_integer(char **pstr, t_specifier *specifier, int isneg);
void	apply_precision_integer(char **pstr, t_specifier *specifier);

#endif
