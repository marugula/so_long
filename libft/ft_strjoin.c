/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:04:02 by marugula          #+#    #+#             */
/*   Updated: 2021/10/11 17:04:04 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*conk;
	size_t	lens1;
	size_t	lens2;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	conk = malloc(lens1 + lens2 + 1);
	if (conk == 0)
		return (0);
	while (i < lens1)
	{
		conk[i] = s1[i];
		i++;
	}
	while (i - lens1 < lens2)
	{
		conk[i] = s2[i - lens1];
		i++;
	}
	conk[i] = '\0';
	return (conk);
}
