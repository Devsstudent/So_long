/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animate_coins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:15:13 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 20:17:34 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_animate_coins(t_info	*game, t_pos cord)
{
	static int			i;
	static int			x;
	void				*coin;
	static t_pos		pos_in_coin;

	if (i == 8 || i == 0)
	{
		i = 0;
		pos_in_coin.x = 0;
	}
	coin = mlx_new_image(game->mlx.mlx, 32, 32);
	sl_mlx_put_img_to_anim(coin, game->img.coins, pos_in_coin);
	sl_mlx_put_img_to_img(game->render, coin, cord);
	mlx_destroy_image(game->mlx.mlx, coin);
	if (x == 10)
	{
		x = 0;
		pos_in_coin.x += 32;
		i++;
	}
	x++;
}
