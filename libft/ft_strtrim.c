/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 15:58:13 by marugula          #+#    #+#             */
/*   Updated: 2021/10/16 15:58:15 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	cmp_setch(const char *set, char ch)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

static char	*find_start(char *str, const char *set)
{
	char	*sd;

	sd = str;
	while (*sd)
	{
		if (cmp_setch(set, *sd) == 0)
			return (sd);
		sd++;
	}
	return (0);
}

static char	*find_end(char *str, const char *set)
{
	char	*sd;

	sd = str + ft_strlen(str) - 1;
	while (sd != str - 1)
	{
		if (cmp_setch(set, *sd) == 0)
			return (sd);
		sd--;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*sd;
	char	*start;
	char	*end;

	if (s1 == 0 || set == 0)
		return (0);
	sd = (char *)s1;
	start = find_start(sd, set);
	if (start == 0)
		return (ft_calloc(1, 1));
	end = find_end(sd, set);
	if (end == 0)
		return (ft_calloc(1, 1));
	sd = ft_calloc(end - start + 1 + 1, sizeof(char));
	if (sd == 0)
		return (0);
	ft_strlcpy(sd, start, end - start + 2);
	return (sd);
}

/*int main(int argv, char **argc)
{
	printf("%s\n", ft_strtrim(argc[1], argc[2]));
}*/
