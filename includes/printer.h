/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:19:35 by jleem             #+#    #+#             */
/*   Updated: 2021/05/27 15:49:24 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include <stdarg.h>

typedef struct	s_printer
{
	char const	*fmt;
	int			fmt_idx;
	int			fmt_len;
	int			nchar;
	va_list		*ap;
}				t_printer;

t_printer		init_printer(char const *format, va_list *ap);
char			printer_getc(t_printer *printer);
char			printer_popc(t_printer *printer);
void			printer_putc(t_printer *printer, char c);
int				printer_chkc(t_printer *printer, char c);

#endif
