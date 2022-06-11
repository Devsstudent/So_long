/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_display_counter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:52:11 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 20:53:02 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_display_counter(t_info *game)
{
	long long	nb;

	nb = game->counter;
	sl_putnbr_img(nb, game, 0);
}

void	sl_putnbr_img(long long nb, t_info *game, int size)
{
	if (nb < 10)
	{
		sl_write_counter(nb, game, size);
		return ;
	}
	sl_putnbr_img(nb / 10, game, size + 1);
	sl_write_counter(nb % 10, game, size);
}

void	sl_write_counter(long long nb, t_info *game, int size)
{
	t_pos	cord;
	void	*digit;
	int		pos_x;

	pos_x = game->center.x + ((ft_strlen(game->map[0]) * 32) - 1) / 2;
	cord.x = (int) nb * 32;
	digit = mlx_new_image(game->mlx.mlx, 32, 32);
	sl_mlx_put_img_to_anim(digit, game->img.number, cord);
	if (game->center.x != 0 || game->center.y != 0)
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, digit,
			(pos_x - 32 * size), (game->center.y - 32));
	else
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, digit,
			(pos_x + 32 * size), (game->center.y));
	mlx_destroy_image(game->mlx.mlx, digit);
}
