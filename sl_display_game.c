/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_display_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:25:26 by marugula          #+#    #+#             */
/*   Updated: 2022/01/19 19:37:10 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_img2(t_mlx *mlx, char ch, int x, int y)
{
	put_img(*mlx, mlx->imgs.empty.img, x, y);
	if (ch == 'X')
		put_img(*mlx, mlx->imgs.ant.img, x, y);
	else if (ch == 'P')
		put_img(*mlx, mlx->imgs.pers.img, x, y);
	else if (ch == 'C')
		put_img(*mlx, mlx->imgs.coin3.img, x, y);
}

void	display_img(t_mlx *mlx, char ch, int x, int y)
{
	if (ch == '1')
		put_img(*mlx, mlx->imgs.wall1.img, x, y);
	else if (ch == 'E')
		put_img(*mlx, mlx->imgs.exit.img, x, y);
	else
		display_img2(mlx, ch, x, y);
	mlx->map[y][x] = ch;
}

t_img	fill_imgs(void *mlx)
{
	t_img	imgs;

	imgs.pers.img = mlx_xpm_file_to_image(mlx, \
		"img/pers.xpm", &imgs.pers.width, &imgs.pers.heigth);
	imgs.coin1.img = mlx_xpm_file_to_image(mlx, \
		"img/coin1.xpm", &imgs.coin1.width, &imgs.coin1.heigth);
	imgs.coin2.img = mlx_xpm_file_to_image(mlx, \
		"img/coin2.xpm", &imgs.coin3.width, &imgs.coin2.heigth);
	imgs.coin3.img = mlx_xpm_file_to_image(mlx, \
		"img/coin3.xpm", &imgs.coin3.width, &imgs.coin3.heigth);
	imgs.coin4.img = mlx_xpm_file_to_image(mlx, \
		"img/coin4.xpm", &imgs.coin4.width, &imgs.coin4.heigth);
	imgs.empty.img = mlx_xpm_file_to_image(mlx, \
		"img/empty.xpm", &imgs.empty.width, &imgs.empty.heigth);
	imgs.exit.img = mlx_xpm_file_to_image(mlx, \
		"img/exit.xpm", &imgs.exit.width, &imgs.exit.heigth);
	imgs.wall1.img = mlx_xpm_file_to_image(mlx, \
		"img/wall1.xpm", &imgs.wall1.width, &imgs.wall1.heigth);
	imgs.wall2.img = mlx_xpm_file_to_image(mlx, \
		"img/wall2.xpm", &imgs.wall2.width, &imgs.wall2.heigth);
	imgs.wall3.img = mlx_xpm_file_to_image(mlx, \
		"img/wall3.xpm", &imgs.wall3.width, &imgs.wall3.heigth);
	return (imgs);
}

void	display_first_frame(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	mlx->collection = 0;
	while (mlx->map[y] != 0)
	{
		x = 0;
		while (mlx->map[y][x] != 0)
		{
			if (mlx->map[y][x] == 'P')
			{
				mlx->x_poz = x;
				mlx->y_poz = y;
			}
			if (mlx->map[y][x] == 'C')
				mlx->collection++;
			display_img(mlx, mlx->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	display_game(char **map)
{
	t_mlx	mlx;
	int		height;
	int		width;

	mlx.mlx = mlx_init();
	map_size(map, &height, &width);
	mlx.mlx_win = mlx_new_window(mlx.mlx, width * 64, height * 64, "so_long");
	mlx.map = map;
	mlx.imgs = fill_imgs(mlx.mlx);
	display_first_frame(&mlx);
	mlx_hook(mlx.mlx_win, 2, 1L << 0, hook_key, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, x_exit, 0);
	mlx_loop(mlx.mlx);
}
