/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:41:41 by marugula          #+#    #+#             */
/*   Updated: 2022/01/19 19:06:46 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	ft_rand(void)
{
	int				fd;
	unsigned long	n;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
		ft_error("open rand error", 0, 0);
	read(fd, &n, sizeof(n));
	close(fd);
	return ((unsigned int)n);
}

void	ft_exit(char *str, int steps)
{
	ft_putstr_fd("\n----------------\n", 1);
	ft_putstr_fd(str, 1);
	if (steps != -1)
	{
		ft_putnbr_fd(steps, 1);
		write(1, "\n", 1);
	}
	exit(1);
}

int	x_exit(void)
{
	ft_exit("Come back soon!\n", -1);
	return (1);
}

void	ft_error(char *texterorr, int iderror, void *need_free)
{
	if (iderror == 1)
	{
		perror(texterorr);
		if (need_free != 0)
			free(need_free);
		exit(iderror);
	}
	if (iderror == 0)
	{
		ft_putstr_fd(texterorr, 2);
		if (need_free != 0)
			free(need_free);
		exit(iderror);
	}
}

void	put_img(t_mlx mlx, void *img, int poz_x, int poz_y)
{
	poz_x *= 64;
	poz_y *= 64;
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img, poz_x, poz_y);
}
