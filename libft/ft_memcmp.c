/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:31:18 by marugula          #+#    #+#             */
/*   Updated: 2021/10/11 16:31:19 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1d;
	unsigned char	*s2d;

	s1d = (unsigned char *)s1;
	s2d = (unsigned char *)s2;
	while (n > 0)
	{
		if (*s1d != *s2d)
			return (*s1d - *s2d);
		s1d++;
		s2d++;
		n--;
	}
	return (0);
}
