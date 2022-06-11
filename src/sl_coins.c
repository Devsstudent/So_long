/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_coins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 23:52:42 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 22:36:47 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

t_bool	sl_check_coins_number(t_info *game)
{
	int	len;
	int	x;
	int	y;

	len = ft_strlen(game->map[0]) - 1;
	y = 0;
	while (y < game->size)
	{
		x = 0;
		while (x < len)
		{
			if (game->map[y][x] == 'C')
				return (TRUE);
			x++;
		}
		y++;
	}
	return (FALSE);
}

t_bool	sl_check_exit_direc(t_info *game, int x, int y)
{
	if (game->pos.y + 32 >= y * 32 && game->pos.y + 32 <= y * 32 + 31
		&& ((game->pos.x >= x * 32 && game->pos.x <= x * 32 + 31)
			|| (game->pos.x + 31 >= x * 32 && game->pos.x <= x * 32 + 31)))
	{
		sl_finish(game, "YOU WIN");
		return (TRUE);
	}
	if (game->pos.y - 1 >= y * 32 && game->pos.y - 1 <= y * 32 + 31
		&& ((game->pos.x >= x * 32 && game->pos.x <= x * 32 + 31)
			|| (game->pos.x + 31 >= x * 32 && game->pos.x <= x * 32 + 31)))
	{
		sl_finish(game, "YOU WIN");
		return (TRUE);
	}
	if (sl_check_exit_direct2(game, x, y))
		return (TRUE);
	return (FALSE);
}

t_bool	sl_check_exit_direct2(t_info *game, int x, int y)
{
	if (game->pos.x + 32 >= x * 32 && game->pos.x + 32 <= x * 32 + 31
		&& ((game->pos.y >= y * 32 && game->pos.y <= y * 32 + 31)
			|| (game->pos.y + 31 >= y * 32 && game->pos.y + 31 <= y * 32 + 31)))
	{
		sl_finish(game, "YOU WIN");
		return (TRUE);
	}
	if (game->pos.x - 1 >= x * 32 && game->pos.x - 1 <= x * 32 + 31
		&& ((game->pos.y >= y * 32 && game->pos.y <= y * 32 + 31)
			|| (game->pos.y + 31 >= y * 32 && game->pos.y + 31 <= y * 32 + 31)))
	{
		sl_finish(game, "YOU WIN");
		return (TRUE);
	}
	return (FALSE);
}

void	sl_check_wall_direct1(t_info *game, int x, int y)
{
	if (game->key.left)
		if (game->pos.x - MOV_SPEED <= x * 32 + 31
			&& game->pos.x - MOV_SPEED >= x * 32
			&& ((game->pos.y >= y * 32 && game->pos.y <= y * 32 + 31)
				|| (game->pos.y + 31 >= y * 32
					&& game->pos.y + 31 <= y * 32 + 31)))
			game->key.left = FALSE;
	if (game->key.right)
		if (game->pos.x + 31 + MOV_SPEED <= x * 32 + 31
			&& game->pos.x + 31 + MOV_SPEED >= x * 32
			&& ((game->pos.y >= y * 32 && game->pos.y <= y * 32 + 31)
				|| (game->pos.y + 31 >= y * 32
					&& game->pos.y + 31 <= y * 32 + 31)))
			game->key.right = FALSE;
}
