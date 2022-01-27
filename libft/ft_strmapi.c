/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:29:15 by marugula          #+#    #+#             */
/*   Updated: 2021/10/18 13:29:16 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rez;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	rez = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (rez == 0)
		return (0);
	while (s[i])
	{
		rez[i] = f(i, s[i]);
		i++;
	}
	return (rez);
}
