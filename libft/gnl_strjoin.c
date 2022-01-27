/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:19:27 by marugula          #+#    #+#             */
/*   Updated: 2022/01/25 13:24:02 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char const *s1, char const *s2)
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
	while (i < lens1)
	{
		conk[i] = s1[i];
		i++;
	}
	while (i - lens1 < lens2)
	{
		conk[i] = s2[i - lens1];
		i++;
		if (conk[i - 1] == '\n')
			break ;
	}
	conk[i] = '\0';
	return (conk);
}
