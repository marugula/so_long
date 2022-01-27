/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:34:01 by marugula          #+#    #+#             */
/*   Updated: 2022/01/11 14:34:28 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_upper_wall(char **map, int length)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < length)
	{
		if (map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_lower_wall(char **map, int length, int heigth)
{
	int	x;
	int	y;

	x = 0;
	y = heigth - 1;
	while (x < length)
	{
		if (map[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_left_wall(char **map, int heigth)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < heigth)
	{
		if (map[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_right_wall(char **map, int length, int heigth)
{
	int	x;
	int	y;

	y = 0;
	x = length - 1;
	while (y < heigth)
	{
		if (map[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_wall(char **map, int length, int heigth)
{
	if (check_upper_wall(map, length) == 0)
		return (0);
	if (check_lower_wall(map, length, heigth) == 0)
		return (0);
	if (check_left_wall(map, heigth) == 0)
		return (0);
	if (check_right_wall(map, length, heigth) == 0)
		return (0);
	return (1);
}
