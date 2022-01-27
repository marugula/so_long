/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:15:52 by marugula          #+#    #+#             */
/*   Updated: 2022/01/10 13:22:04 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strclr(char *s)
{
	while (*s)
	{
		*s = 0;
		s++;
	}
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
}

char	*check_remainsbuf(char **str, char *buf)
{
	char	*p_n;
	char	*tmp;

	p_n = 0;
	if (buf[0] != 0)
	{
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			tmp = *str;
			*str = ft_strdup(buf);
			free(tmp);
			ft_strcpy(buf, ++p_n);
		}
		else
		{
			tmp = *str;
			*str = ft_strdup(buf);
			free(tmp);
		}
	}
	return (p_n);
}

char	*fill_str(char *buf, char *str, char **p_n, int fd)
{
	int		count_symb;
	char	*tmp;

	count_symb = read(fd, buf, BUFFER_SIZE);
	if (count_symb < 0)
	{
		free(str);
		return (0);
	}
	while (*p_n == 0 && count_symb)
	{
		buf[count_symb] = 0;
		tmp = str;
		str = gnl_strjoin(str, buf);
		free(tmp);
		*p_n = ft_strchr(buf, '\n');
		if (*p_n == 0)
			count_symb = read(fd, buf, BUFFER_SIZE);
		else
			ft_strcpy(buf, ++(*p_n));
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*str;
	char		*p_n;

	p_n = 0;
	str = ft_strdup("");
	p_n = check_remainsbuf(&str, buf);
	if (p_n == 0)
	{
		str = fill_str(buf, str, &p_n, fd);
		if (str == 0)
			return (0);
	}
	if (str[0] == 0)
	{
		ft_strclr(buf);
		free(str);
		return (0);
	}
	if (p_n == 0)
		ft_strclr(buf);
	return (str);
}

/*int main()
{
	int fd = open("text.txt", O_RDONLY);

	for(int i = 0; i < 6; i++)
		printf("%d line: (((%s)))",i+1, get_next_line(fd));
	close(fd);
}*/
