/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marugula <marugula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:43:00 by marugula          #+#    #+#             */
/*   Updated: 2022/01/19 18:41:48 by marugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>
# include <fcntl.h>

# include <stdlib.h>

typedef struct s_img_data
{
	void		*img;
	int			width;
	int			heigth;
}	t_img_data;

typedef struct s_img
{
	t_img_data	wall1;
	t_img_data	wall2;
	t_img_data	wall3;
	t_img_data	empty;
	t_img_data	pers;
	t_img_data	ant;
	t_img_data	coin1;
	t_img_data	coin2;
	t_img_data	coin3;
	t_img_data	coin4;
	t_img_data	exit;
}	t_img;

typedef struct t_mlx_win_data
{
	void		*mlx;
	void		*mlx_win;
	int			x_poz;
	int			y_poz;
	int			collection;
	unsigned	steps;
	char		**map;
	t_img		imgs;
}	t_mlx;


/* sl.c */
void	map_size(char **map, int *height, int *width);
int		fill_random_ant(char **map, int square);


/* sl_utils.c */
void				ft_error(char *texterorr, int iderror, void *need_free);
unsigned int		ft_rand();
void				ft_exit(char *str, int steps);
void				put_img(t_mlx mlx, void *img, int poz_x, int poz_y);
int					x_exit(void);

/* sl_validation_map.c */
int					validation_map(char **map);

/* sl_check_wall.c */
int					check_wall(char **map, int length, int heigth);

/* sl_read_and_split.c */
char				**read_and_split(char *name_map);
int					check_format_map(char *map_name);

/* sl_change_inmap.c */
int					bg_move(t_mlx *mlx);
int					hook_key(int key, t_mlx *mlx);

/* sl_dysplay_game.c */
void				display_game(char **map);
void				display_img(t_mlx *mlx, char ch, int x, int y);

#endif