/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:32:06 by marugula          #+#    #+#             */
/*   Updated: 2021/10/18 13:32:08 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1d;
	unsigned char	*s2d;

	s1d = (unsigned char *)s1;
	s2d = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s1d != *s2d)
			return (*s1d - *s2d);
		if (*s1d == '\0')
			return (0);
		s1d++;
		s2d++;
		n--;
	}
	return (0);
}
