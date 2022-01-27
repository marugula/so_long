/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:52:18 by marugula          #+#    #+#             */
/*   Updated: 2021/10/11 16:52:19 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sfind;

	sfind = (char *)s;
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*sfind && *sfind != (char)c)
		sfind++;
	if (*sfind == '\0')
		return (0);
	else
		return (sfind);
}
