/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_validation_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:36:19 by marugula          #+#    #+#             */
/*   Updated: 2022/01/17 15:57:19 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_ch_inmap(char ch, char **map, int length, int heigth)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (x < length)
	{
		y = 0;
		while (y < heigth)
		{
			if (map[y][x] == ch)
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

int	valid_ch_inmap(char **map, int length, int heigth)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < length)
	{
		y = 0;
		while (y < heigth)
		{
			if (map[y][x] != '1' && map[y][x] != '0'
				&& map[y][x] != 'P' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'A')
			{
				ft_putchar_fd(map[y][x], 1);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	equality_length(char **map)
{
	int	heigth;

	heigth = 0;
	while (map[heigth] != 0)
	{
		if (ft_strlen(map[0]) != ft_strlen(map[heigth]))
			return (0);
		heigth++;
	}
	return (heigth);
}

int	validation_map(char **map)
{
	int	length;
	int	heigth;

	heigth = equality_length(map);
	if (heigth < 3)
		return (0);
	length = ft_strlen(map[0]);
	if (valid_ch_inmap(map, length, heigth) == 0)
		return (0);
	if (check_wall(map, length, heigth) == 0)
		return (0);
	if (find_ch_inmap('E', map, length, heigth) == 0)
		return (0);
	if (find_ch_inmap('C', map, length, heigth) == 0)
		return (0);
	if (find_ch_inmap('P', map, length, heigth) != 1)
		return (0);
	else
		return (1);
}
