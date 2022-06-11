/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_core.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:57:35 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 20:50:11 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

t_bool	sl_game(t_info *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (FALSE);
	game->mlx.win = mlx_new_window(game->mlx.mlx, 2560, 1440, "trip_in_boat");
	if (!game->mlx.win)
		return (FALSE);
	if (!sl_load_img(game))
		return (FALSE);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.back, 0, 0);
	game->render = mlx_new_image(game->mlx.mlx,
			(ft_strlen(game->map[0]) - 1) * 32, game->size * 32);
	sl_init_game(game);
	mlx_loop_hook(game->mlx.mlx, &(sl_hook), game);
	mlx_hook(game->mlx.win, 33, 1L << 1, &(sl_close), game);
	mlx_hook(game->mlx.win, 3, 1L << 1, &(sl_hook_release), game);
	mlx_hook(game->mlx.win, 2, 1L << 0, &(sl_hook_press), game);
	mlx_loop(game->mlx.mlx);
	return (TRUE);
}

void	sl_display_background(t_info *game)
{
	int		len;
	int		x;
	int		y;
	t_pos	cord;

	len = ft_strlen(game->map[0]) - 1;
	y = -1;
	while (++y < game->size)
	{
		x = -1 ;
		while (++x < len)
		{
			cord.x = x * 32;
			cord.y = y * 32;
			if (game->map[y][x] == '1')
				sl_mlx_put_img_to_img(game->render, game->img.wall, cord);
			else if (game->map[y][x] == '0')
				sl_mlx_put_img_to_img(game->render, game->img.background, cord);
			else if (game->map[y][x] == 'C')
				sl_animate_coins(game, cord);
			else if (game->map[y][x] == 'E')
				sl_animate_exit(game, cord);
		}
	}
}

void	sl_display_ship(t_info *game)
{
	t_pos	cord;

	cord.x = game->pos.x;
	cord.y = game->pos.y;
	sl_mlx_put_img_to_img(game->render, game->ship, cord);
}
