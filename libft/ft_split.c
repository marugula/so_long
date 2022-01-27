/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:58:24 by marugula          #+#    #+#             */
/*   Updated: 2022/01/10 18:12:10 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_word(int *start, char *str, char c)
{
	int	end;

	while (1)
	{
		if (str[*start] == 0)
			return (-1);
		if (str[*start] != c)
			break ;
		(*start)++;
	}
	end = *start;
	while (1)
	{
		if (str[end] == c || str[end] == 0)
			return (end);
		end++;
	}
	return (0);
}

static size_t	count_w(char *str, char c)
{
	size_t	count;
	int		start;
	int		end;

	start = 0;
	count = 0;
	while (*str)
	{
		end = find_word(&start, str, c);
		if (end == -1)
			return (count);
		count++;
		if (end == 0)
			return (count);
		start = end;
	}
	return (0);
}

static char	**record_words(char **big, char *str, char c, size_t count)
{
	int		start;
	int		end;
	size_t	i;

	i = 0;
	start = 0;
	while (i != count)
	{
		end = find_word(&start, str, c);
		big[i] = malloc((end - start + 1) * sizeof(char));
		if (big[i] == 0)
			return (0);
		ft_strlcpy(big[i], str + start, end - start + 1);
		start = end;
		i++;
	}
	return (big);
}

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i++] != 0)
		free(arr[i]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	char	*sd;
	size_t	count_word;

	dest = 0;
	if (s == 0)
		return (0);
	sd = (char *)s;
	count_word = count_w(sd, c);
	dest = (char **)ft_calloc((count_word + 1), sizeof(char *));
	if (dest == 0)
		return ((void *) NULL);
	if (record_words(dest, sd, c, count_word) == 0)
	{
		free_all(dest);
		return ((void *) NULL);
	}
	return (dest);
}
/*int main(int argc, char **argv)
{
	char **tab = ft_split("chinimala", ' ');
	printf("\n\n%s", tab[0]);
	freeTab(tab);
	tab = ft_split("     ", ' ');
	printf("\n\n%s", tab[0]);
	freeTab(tab);
	tab = ft_split("           gohome" , ' ');
	printf("\n\n%s", tab[0]);
	//printf("%p\n\n", tab);
}*/
