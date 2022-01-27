/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_change_inmap_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:43:23 by marugula          #+#    #+#             */
/*   Updated: 2022/01/20 11:33:34 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_mlx mlx)
{
	int			x;
	int			y;
	t_img_data	open;

	y = 0;
	open.img = mlx_xpm_file_to_image(mlx.mlx, \
		"img/exit2.xpm", &open.width, &open.heigth);
	while (mlx.map[y] != 0)
	{
		x = 0;
		while (mlx.map[y][x] != 0)
		{
			if (mlx.map[y][x] == 'E')
				put_img(mlx, open.img, x, y);
			x++;
		}
		y++;
	}
}

void	step(t_mlx *mlx, int step_x, int step_y)
{
	if (mlx->map[mlx->y_poz + step_y][mlx->x_poz + step_x] == '1')
		return ;
	if (mlx->map[mlx->y_poz + step_y][mlx->x_poz + step_x] == 'E')
	{
		if (mlx->collection <= 0)
			ft_exit("Congratulations, you won\nYour score: ", mlx->steps);
		return ;
	}
	if (mlx->map[mlx->y_poz + step_y][mlx->x_poz + step_x] == 'X')
		ft_exit("You failed((\nTry again!\n", -1);
	if (mlx->map[mlx->y_poz + step_y][mlx->x_poz + step_x] == 'C')
	{
		mlx->collection--;
		if (mlx->collection == 0)
			open_exit(*mlx);
	}
	display_img(mlx, '0', mlx->x_poz, mlx->y_poz);
	mlx->x_poz += step_x;
	mlx->y_poz += step_y;
	display_img(mlx, 'P', mlx->x_poz, mlx->y_poz);
}

int	hook_key(int key, t_mlx *mlx)
{
	char	*str;

	if (key == 53)
		ft_exit("Come back soon!\n", -1);
	if (key == 13 || (key >= 0 && key <= 2) || (key >= 123 && key <= 126))
	{
		str = ft_itoa(++mlx->steps);
		display_img(mlx, '1', 0, 0);
		mlx_string_put(mlx->mlx, mlx->mlx_win, 20, 20, 0x000, str);
		free(str);
		if (key == 13 || key == 126)
			step(mlx, 0, -1);
		if (key == 0 || key == 123)
			step(mlx, -1, 0);
		if (key == 1 || key == 125)
			step(mlx, 0, 1);
		if (key == 2 || key == 124)
			step(mlx, 1, 0);
	}
	return (1);
}

void	step_ant(t_mlx *mlx, int x, int y)
{
	int	step_x;
	int	step_y;

	step_x = ft_rand() % 3 - 1;
	if (step_x != 0)
		step_y = 0;
	else
		step_y = ft_rand() % 3 - 1;
	if (mlx->map[y + step_y][x + step_x] == '1' ||
		mlx->map[y + step_y][x + step_x] == 'E' ||
		mlx->map[y + step_y][x + step_x] == 'C' ||
		mlx->map[y + step_y][x + step_x] == 'X')
		return ;
	display_img(mlx, '0', x, y);
	display_img(mlx, 'X', x + step_x, y + step_y);
	if (x + step_x == mlx->x_poz && y + step_y == mlx->y_poz)
		ft_exit("You failed((\nTry again!\n", -1);
}

int	bg_move(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map[y] != 0)
	{
		x = 0;
		while (mlx->map[y][x] != 0)
		{
			if (mlx->map[y][x] == 'C' && ft_rand() % 5 == 0)
				display_img(mlx, 'C', x, y);
			if (mlx->map[y][x] == '1' && ft_rand() % 1 == 0 &&
				x + y != 0)
				display_img(mlx, '1', x, y);
			if (mlx->map[y][x] == 'X' && ft_rand() % 40 == 1)
				step_ant(mlx, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
