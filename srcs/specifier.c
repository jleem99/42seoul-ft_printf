/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 21:57:57 by jleem             #+#    #+#             */
/*   Updated: 2021/02/20 02:07:34 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"
#include "printer.h"
#include <stdlib.h>

static int		parse_flag(t_specifier *specifier, t_printer *printer)
{
	char	c;

}

static int		parse_width(t_specifier *specifier, t_printer *printer)
{

}

static int		parse_precision(t_specifier *specifier, t_printer *printer)
{

}

static int		parse_length(t_specifier *specifier, t_printer *printer)
{

}

/*
** parse_specifier doesn't validate specifier
*/

t_specifier		*parse_specifier(t_printer *printer)
{
	t_specifier		*specifier;

	specifier = malloc(sizeof(t_specifier));
	if (!specifier)
		return (NULL);
	if (!parse_flag(specifier, printer) ||
		!parse_width(specifier, printer) ||
		!parse_precision(specifier, printer) ||
		!parse_length(specifier, printer) ||
		printer->fmt_idx >= printer->fmt_len)
	{
		free(specifier);
		return (NULL);
	}
	specifier->specifier = printer->fmt[printer->fmt_idx++];
	return (specifier);
}
