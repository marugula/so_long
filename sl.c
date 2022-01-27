/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:37:31 by marugula          #+#    #+#             */
/*   Updated: 2022/01/19 19:27:19 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fill_random_ant(char **map, int square)
{
	int				count_ant;
	int				x;
	int				y;

	count_ant = 0;
	y = 0;
	while (map[y] != 0)
	{
		x = 0;
		while (map[y][x] != 0)
		{
			if (map[y][x] == '0' && ft_rand() % 15 == 0)
			{
				map[y][x] = 'X';
				if (count_ant > (square / 15))
					return (count_ant);
				count_ant++;
			}
			x++;
		}
		y++;
	}
	return (count_ant);
}

void	map_size(char **map, int *height, int *width)
{
	*height = 0;
	*width = 0;
	while (map[*height] != 0)
		(*height)++;
	while (map[0][*width] != 0)
		(*width)++;
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		ft_error("Pass the path of one map!", 0, 0);
	if (check_format_map(argv[1]) == 0)
		ft_error("Error! Pass the map in the format (.ber)!\n", 0, 0);
	map = read_and_split(argv[1]);
	display_game(map);
}
