/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:41:46 by marugula          #+#    #+#             */
/*   Updated: 2021/10/18 13:41:48 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*sfind;
	char	*mem;

	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	sfind = (char *)s;
	mem = 0;
	while (*sfind)
	{
		if (*sfind == (char)c)
			mem = sfind;
		sfind++;
	}
	return (mem);
}
