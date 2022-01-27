/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:27:51 by marugula          #+#    #+#             */
/*   Updated: 2021/10/18 13:27:53 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int main()
{
	char src[] = "coucou";
	char dest[] = "\0AAAAAAAAa";
	char src1[] = "coucou";
	char dest1[] = "\0AAAAAAAAa";

	printf("%lu\n", strlcpy(dest, src, 2));
	printf("%s     %s\n", dest, src);
	printf("%c     %c   %c\n\n", dest[0], dest[1], dest[2]);

	printf("%lu\n", ft_strlcpy(dest1, src1, 2));
	printf("%s     %s\n", dest1, src1);
	printf("%c     %c   %c\n\n", dest1[0], dest1[1], dest1[2]);
}*/
