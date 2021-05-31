/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:31 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 22:41:01 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	return (a > b ? b : a);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t const	slen = ft_strlen(s);
	size_t			copylen;
	char			*ret;

	if (!s || start >= slen)
		return (ft_strdup(""));
	copylen = ft_min(slen - start, len);
	if (!(ret = malloc(sizeof(*ret) * (copylen + 1))))
		return (NULL);
	ft_memcpy(ret, s + start, copylen);
	ret[copylen] = '\0';
	return (ret);
}
