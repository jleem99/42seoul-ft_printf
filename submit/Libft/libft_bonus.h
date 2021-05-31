/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:33:51 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 01:31:44 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include "libft.h"
# include <stddef.h>
# include <stdint.h>

/*
** Personal Functions
*/
void			ft_free_split(char **split);

/*
** Personal Functions (libc)
*/
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_isspace(int c);
int				ft_strcmp(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strcat(char *dest, char *src);

/*
** Personal Functions (array)
*/
typedef struct	s_array
{
	void		**data;
	size_t		size;
}				t_array;

t_array			*ft_make_array(size_t size);
void			ft_free_array(t_array *arr);
void			ft_free_array_data(t_array *arr);
void			ft_free_array_all(t_array *arr);
int				ft_array_push(t_array *arr, void *element);
void			*ft_array_pop(t_array *arr);

/*
** Personal Functions (bigint)
*/

typedef struct	s_bigint
{
	uint8_t		*data;
	uint8_t		base;
	size_t		size;
}				t_bigint;

t_bigint		*make_bigint(size_t size, uint8_t base);
void			free_bigint(t_bigint *bigint);

t_bigint		*bigint_copy(t_bigint *bigint);
uint8_t			*bigint_copy_data(t_bigint *bigint);
t_bigint		*bigint_append(t_bigint *bigint1, t_bigint *bigint2);
void			bigint_resize(t_bigint *bigint, size_t new_size);
void			bigint_resize_reverse(t_bigint *bigint, size_t new_size);

void			bigint_set_value(t_bigint *bigint, uint64_t value);
void			bigint_set_digit(t_bigint *bigint,
								uint16_t value,
								size_t byteidx);
void			bigint_add_digit(t_bigint *bigint,
								uint8_t addend,
								size_t byteidx);
void			bigint_add(t_bigint *bigint, t_bigint *addend);
void			bigint_multiply(t_bigint *bigint, uint8_t multiplier);

void			bigint_shift_bytes(t_bigint *bigint, int bytes);
void			bigint_shift_bits(t_bigint *bigint, int bits);

char			*bigint_to_string(t_bigint *bigint);
char			*bigint_to_string_hex(t_bigint *bigint, char base);

void			bigint_inspect_byte(t_bigint const *bigint, size_t byteidx);
void			bigint_inspect_byte_decimal(t_bigint const *bigint,
											size_t byteidx);
void			bigint_inspect(t_bigint const *bigint);
void			bigint_inspect_decimal(t_bigint const *bigint);

#endif
