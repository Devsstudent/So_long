/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animate_enemy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:22:21 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 20:30:51 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_animate_enemy(t_info *game, float i)
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
			if (game->map[y][x] == 'T')
				sl_enemy_animation(game, cord, i);
		}
	}
}

void	sl_enemy_animation(t_info *game, t_pos cord, int frame)
{
	static int		i;
	void			*enemy;
	static t_pos	pos_in_enemy;

	if (i == 0 || i == 6)
	{
		i = 4;
		pos_in_enemy.x = 32 * 4;
	}
	enemy = mlx_new_image(game->mlx.mlx, 32, 32);
	sl_mlx_put_img_to_anim(enemy, game->img.enemy, pos_in_enemy);
	sl_mlx_put_img_to_img(game->render, enemy, cord);
	mlx_destroy_image(game->mlx.mlx, enemy);
	if (frame % 25 == 0)
	{
		pos_in_enemy.x += 32;
		i++;
	}
}

void	sl_display_enemy(t_info *game)
{
	int		len;
	int		x;
	int		y;
	t_pos	cord;

	len = ft_strlen(game->map[0]) - 1;
	y = -1;
	while (++y < game->size)
	{
		x = -1;
		while (++x < len)
		{
			cord.x = x * 32;
			cord.y = y * 32;
			if (game->map[y][x] == 'W')
				sl_animate_exit(game, cord);
		}
	}
}
