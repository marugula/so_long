/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:40:07 by marugula          #+#    #+#             */
/*   Updated: 2021/10/18 13:40:09 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	char	*mem;

	b = (char *)big;
	l = (char *)little;
	if (*l == '\0')
		return (b);
	while ((size_t)(b - big) < len && *b)
	{
		l = (char *)little;
		mem = b;
		while ((size_t)(b - big) < len && *b)
		{
			if (*b != *l)
				break ;
			++l;
			if (*l == '\0')
				return (mem);
			b++;
		}
		b = mem;
		b++;
	}
	return (0);
}

/*int main(int argc, char **argv)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";

	printf("%p\n", strnstr(argv[1], argv[2], -1));
	printf("%p\n", ft_strnstr(argv[1], argv[2], -1));    
}*/
