/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:18 by jleem             #+#    #+#             */
/*   Updated: 2021/01/29 07:45:05 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_chr(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_count_strs(char const *s, char c)
{
	int	str_num;

	str_num = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			str_num++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (str_num);
}

static void	*ft_split_free(char **buf, int str_idx)
{
	while (str_idx >= 0)
		free(buf[str_idx--]);
	free(buf);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char		**ret;
	int const	str_num = ft_count_strs(s, c);
	int			str_idx;
	int			word_idx;

	if (!(ret = malloc(sizeof(*ret) * (str_num + 1))))
		return (NULL);
	str_idx = 0;
	while (str_idx < str_num)
	{
		while (*s == c)
			s++;
		if (!(ret[str_idx] = malloc(ft_strlen_chr(s, c) + 1)))
			return (ft_split_free(ret, str_idx - 1));
		word_idx = 0;
		while (*s != '\0' && *s != c)
			ret[str_idx][word_idx++] = *(s++);
		ret[str_idx++][word_idx] = '\0';
	}
	ret[str_idx] = NULL;
	return (ret);
}
