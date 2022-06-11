/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:11:03 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 22:27:56 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

void	sl_init_game(t_info *game)
{
	int	len;
	int	x;
	int	y;

	game->list_e = NULL;
	game->list_t = NULL;
	sl_init_struct(game);
	len = ft_strlen(game->map[0]) - 1;
	y = -1;
	while (++y < game->size)
	{
		x = -1;
		while (++x < len)
		{
			if (game->map[y][x] == 'P')
				sl_setup_start(game, x, y);
			if (game->map[y][x] == 'E')
				sl_setup_exit(game, x, y);
			if (game->map[y][x] == 'T')
				sl_setup_enemy(game, x, y);
			else
				sl_load_initial(game, game->map[y][x], x, y);
		}
	}
}

void	sl_init_struct(t_info *game)
{
	game->key.up = FALSE;
	game->key.down = FALSE;
	game->key.left = FALSE;
	game->key.right = FALSE;
	game->end = FALSE;
	game->center.x = (2560 - (ft_strlen(game->map[0]) - 1) * 32) / 2;
	game->center.y = (1440 - game->size * 32) / 2;
	game->counter = 0;
	game->enemy = FALSE;
}

void	sl_setup_exit(t_info *game, int x, int y)
{
	t_list	*new;
	t_pos	*coord;

	coord = (t_pos *) malloc(sizeof(t_pos));
	if (!coord)
		return ;
	coord->x = x;
	coord->y = y;
	new = ft_lstnew(coord);
	ft_lstadd_back(&game->list_e, new);
	game->map[y][x] = '0';
}

void	sl_setup_start(t_info *game, int x, int y)
{
	t_pos	coord;

	game->ship = game->img.ship_u;
	game->pos.x = x * 32;
	game->pos.y = y * 32;
	coord.x = game->pos.x;
	coord.y = game->pos.y;
	sl_mlx_put_img_to_img(game->render, game->ship, coord);
	game->map[y][x] = '0';
}

void	sl_load_initial(t_info *game, char c, int x, int y)
{
	t_pos	coord;

	coord.x = x * 32;
	coord.y = y * 32;
	if (c == '0')
		sl_mlx_put_img_to_img(game->render, game->img.background, coord);
	else if (c == '1')
		sl_mlx_put_img_to_img(game->render, game->img.wall, coord);
	else if (c == 'C')
		sl_mlx_put_img_to_img(game->render, game->img.coins, coord);
	sl_replace_enemy(game);
}
