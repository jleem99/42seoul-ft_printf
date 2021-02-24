/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getarg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 00:25:07 by jleem             #+#    #+#             */
/*   Updated: 2021/02/24 00:53:41 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETARG_H
# define GETARG_H

# include <stddef.h>
# include <stdint.h>

typedef struct s_printer	t_printer;
typedef struct s_specifier	t_specifier;

intmax_t	getarg_integer(t_printer *printer, t_specifier *specifier);
uintmax_t	getarg_uinteger(t_printer *printer, t_specifier *specifier);

#endif
