/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animate_whirl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:31:15 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 20:32:42 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

void	sl_animate_exit(t_info *game, t_pos cord)
{
	static int		i;
	void			*exit;
	static t_pos	pos_in_exit;
	static int		x;

	if (i == 0 || i == 4)
	{
		i = 0;
		pos_in_exit.x = 0;
	}
	exit = mlx_new_image(game->mlx.mlx, 32, 32);
	sl_mlx_put_img_to_anim(exit, game->img.exit, pos_in_exit);
	sl_mlx_put_img_to_img(game->render, exit, cord);
	mlx_destroy_image(game->mlx.mlx, exit);
	if (x == 10)
	{
		x = 0;
		pos_in_exit.x += 32;
		i++;
	}
	x++;
}
