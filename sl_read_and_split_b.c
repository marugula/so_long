/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_read_and_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:23:50 by marugula          #+#    #+#             */
/*   Updated: 2022/01/19 18:43:42 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format_map(char *map_name)
{
	int	i;

	i = 0;
	while (map_name[i])
		i++;
	if (ft_strnstr(map_name, ".ber", ft_strlen(map_name)) == map_name + i - 4)
		return (1);
	else
		return (0);
}

char	*read_all_file(char *file_name)
{
	int		fd;
	char	*str;
	char	*tmp1;
	char	*tmp2;

	str = ft_calloc(1, 1);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("Open map error", 1, str);
	while (1)
	{
		tmp1 = get_next_line(fd);
		tmp2 = str;
		if (tmp1 == 0)
			return (str);
		str = ft_strjoin(str, tmp1);
		free(tmp1);
		free(tmp2);
	}
	return (0);
}

char	*cliping_map(char *file_inline)
{
	int		i;
	int		start;
	char	*map_inline;

	i = 0;
	while (file_inline[i] != 0)
	{
		if (file_inline[i] != '\n')
			break ;
		i++;
	}
	start = i;
	while (file_inline[i] != 0)
	{
		if (file_inline[i] == '\n' && (file_inline[i + 1] == '\n'
				|| file_inline[i + 1] == 0))
			break ;
		i++;
	}
	file_inline[i] = 0;
	map_inline = ft_strdup(file_inline + start);
	if (map_inline == 0)
		ft_error("Strdup error", 1, file_inline);
	return (map_inline);
}

char	**split_map(char *file_inline)
{
	char	**map;
	char	*map_inline;

	map_inline = cliping_map(file_inline);
	free(file_inline);
	map = ft_split(map_inline, '\n');
	if (map == 0)
		ft_error("split error", 1, map_inline);
	free(map_inline);
	return (map);
}

char	**read_and_split(char *name_map)
{
	char	**map;
	char	*file_inline;

	file_inline = read_all_file(name_map);
	if (*file_inline == 0)
		ft_error("Read file error", 1, file_inline);
	map = split_map(file_inline);
	if (validation_map(map) == 0)
		ft_error("Error!\nMisconfiguration file", 0, 0);
	return (map);
}
