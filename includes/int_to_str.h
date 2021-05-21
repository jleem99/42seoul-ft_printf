/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_str.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:59:07 by jleem             #+#    #+#             */
/*   Updated: 2021/05/21 22:01:18 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_TO_STR_H
# define INT_TO_STR_H

# include <stdint.h>

char	*intmax_to_str_10(intmax_t n);
char	*uintmax_to_str_10(uintmax_t n);
char	*uintmax_to_str_8(uintmax_t n);
char	*uintmax_to_str_16(uintmax_t n, char base);

#endif
