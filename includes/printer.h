/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:19:35 by jleem             #+#    #+#             */
/*   Updated: 2021/07/08 17:55:40 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include <stdarg.h>
# include <stddef.h>

typedef struct s_printer
{
	char const	*fmt;
	char		*putstr;
	size_t		fmt_idx;
	size_t		fmt_len;
	size_t		nchar;
	va_list		*ap;
}				t_printer;

t_printer		init_printer(char *putstr, char const *format, va_list *ap);
char			printer_getc(t_printer *printer);
char			printer_popc(t_printer *printer);
void			printer_putc(t_printer *printer, char c);
int				printer_chkc(t_printer *printer, char c);

#endif
