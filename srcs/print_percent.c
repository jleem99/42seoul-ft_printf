/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 22:53:43 by jleem             #+#    #+#             */
/*   Updated: 2021/02/20 22:53:49 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "printer.h"
#include "specifier.h"

void	print_percent(t_printer *printer, t_specifier *specifier) // validate malloc
{
	char	*str;

	str = "[percent]";
	print(str, printer, specifier);
}
