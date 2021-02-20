/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 20:34:49 by jleem             #+#    #+#             */
/*   Updated: 2021/02/21 07:53:55 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

typedef struct s_printer	t_printer;
typedef struct s_specifier	t_specifier;

void	print(char const *str, t_printer *printer, t_specifier *specifier);
void	print_integer(t_printer *printer, t_specifier *specifier);
void	print_float(t_printer *printer, t_specifier *specifier);
void	print_char(t_printer *printer, t_specifier *specifier);
void	print_str(t_printer *printer, t_specifier *specifier);
void	print_ptr(t_printer *printer, t_specifier *specifier);
void	print_nchar(t_printer *printer, t_specifier *specifier);
void	print_percent(t_printer *printer, t_specifier *specifier); // print_percent(printer) ???

/*
** Utility Functions
*/

# include <stdint.h>

char	*ft_imtoa(intmax_t n);

#endif
