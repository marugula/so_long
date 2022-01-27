/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:45:27 by marugula          #+#    #+#             */
/*   Updated: 2021/10/11 18:45:29 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*fillcat(char *d, char *s, size_t i)
{
	while (*s != '\0')
	{
		if (i > 1)
		{
			*d = *s;
			d++;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (s);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	char	*d;
	char	*s;

	i = size;
	d = (char *)dst;
	s = (char *)src;
	while (i != 0 && *d != '\0')
	{
		d++;
		i--;
	}
	dlen = d - (char *)dst;
	if (i == 0)
		return (dlen + ft_strlen(s));
	return (dlen + fillcat(d, s, i) - src);
}
