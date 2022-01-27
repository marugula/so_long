/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:52:40 by marugula          #+#    #+#             */
/*   Updated: 2021/10/18 13:52:46 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	size;

	if (s == 0)
		return (0);
	size = ft_strlen(s);
	i = 0;
	if (start >= size)
	{
		subs = malloc(1);
		if (subs == 0)
			return (0);
		*subs = '\0';
		return (subs);
	}
	if (len > size)
		subs = malloc(size + 1);
	else
		subs = malloc(len + 1);
	if (subs == 0)
		return (0);
	ft_strlcpy(subs, s + start, len + 1);
	return (subs);
}

/*int main(int argc, char **argv)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char* s = ft_substr(argv[1], 0, 4200);
	printf("%s     %p\n", s, s); 
	free(s);
}*/
