/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:11:59 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 21:16:35 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

t_bool	sl_load_img(t_info *game)
{
	int	width;
	int	height;

	if (!sl_load_ship(game))
		return (FALSE);
	game->img.coins = mlx_xpm_file_to_image(game->mlx.mlx,
			COINS, &width, &height);
	game->img.background = mlx_xpm_file_to_image(game->mlx.mlx,
			BACKGROUND, &width, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx.mlx,
			EXIT, &width, &height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL, &width, &height);
	game->img.back = mlx_xpm_file_to_image(game->mlx.mlx,
			BACK, &width, &height);
	game->img.enemy = mlx_xpm_file_to_image(game->mlx.mlx,
			ENEMY, &width, &height);
	game->img.number = mlx_xpm_file_to_image(game->mlx.mlx,
			NUMBER, &width, &height);
	if (!game->img.exit || !game->img.background || !game->img.coins)
		return (FALSE);
	if (!game->img.back || !game->img.enemy
		|| !game->img.wall || !game->img.number)
		return (FALSE);
	return (TRUE);
}

t_bool	sl_load_ship(t_info *game)
{
	int	width;
	int	height;

	game->img.ship_d = mlx_xpm_file_to_image(game->mlx.mlx,
			SHIP_D, &width, &height);
	game->img.ship_u = mlx_xpm_file_to_image(game->mlx.mlx,
			SHIP_U, &width, &height);
	game->img.ship_l = mlx_xpm_file_to_image(game->mlx.mlx,
			SHIP_L, &width, &height);
	game->img.ship_r = mlx_xpm_file_to_image(game->mlx.mlx,
			SHIP_R, &width, &height);
	game->img.ship_d_l = mlx_xpm_file_to_image(game->mlx.mlx,
			SHIP_D_L, &width, &height);
	game->img.ship_u_l = mlx_xpm_file_to_image(game->mlx.mlx,
			SHIP_U_L, &width, &height);
	game->img.ship_d_r = mlx_xpm_file_to_image(game->mlx.mlx,
			SHIP_D_R, &width, &height);
	game->img.ship_u_r = mlx_xpm_file_to_image(game->mlx.mlx,
			SHIP_U_R, &width, &height);
	if (!game->img.ship_l || !game->img.ship_u || !game->img.ship_d
		|| !game->img.ship_r || !game->img.ship_d_l || !game->img.ship_d_r
		|| !game->img.ship_u_l || !game->img.ship_u_r)
		return (FALSE);
	return (TRUE);
}
