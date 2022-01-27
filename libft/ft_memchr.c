/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:20:07 by marugula          #+#    #+#             */
/*   Updated: 2021/10/11 16:20:09 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sfind;
	char	cfind;

	sfind = (char *)s;
	cfind = (char)c;
	while (n > 0)
	{
		if (*sfind == cfind)
			return (sfind);
		n--;
		sfind++;
	}
	return (0);
}
