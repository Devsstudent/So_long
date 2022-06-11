/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sl_hitbox.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: odessein <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/06 20:57:41 by odessein		  #+#	#+#			 */
/*   Updated: 2022/06/10 22:36:54 by odessein         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "sl.h"

void	sl_check_coins(t_info *game)
{
	int	len;
	int	x;
	int	y;

	len = ft_strlen(game->map[0]) - 1;
	y = -1;
	while (++y < game->size)
	{
		x = -1;
		while (++x < len)
			if (game->map[y][x] == 'C')
				sl_check_coins_direc(game, x, y);
	}
}

t_bool	sl_check_exit(t_info *game)
{
	int	len;
	int	x;
	int	y;

	len = ft_strlen(game->map[0]) - 1;
	y = 0;
	while (++y < game->size)
	{
		x = -1;
		while (++x < len)
			if (game->map[y][x] == 'E')
				if (sl_check_exit_direc(game, x, y))
					return (TRUE);
	}
	return (FALSE);
}

void	sl_check_coins_direc(t_info *game, int x, int y)
{
	if (game->pos.y + 31 >= y * 32 && game->pos.y + 31 <= y * 32 + 31
		&& ((game->pos.x >= x * 32 && game->pos.x <= x * 32 + 31)
			|| (game->pos.x + 31 >= x * 32 && game->pos.x <= x * 32 + 31)))
		game->map[y][x] = '0';
	if (game->pos.y >= y * 32 && game->pos.y <= y * 32 + 31
		&& ((game->pos.x >= x * 32 && game->pos.x <= x * 32 + 31)
			|| (game->pos.x + 31 >= x * 32 && game->pos.x <= x * 32 + 31)))
		game->map[y][x] = '0';
	if (game->pos.x + 31 >= x * 32 && game->pos.x + 32 <= x * 32
		&& ((game->pos.y >= y * 32 && game->pos.y <= y * 32 + 31)
			|| (game->pos.y + 31 >= y * 32 && game->pos.y + 31 <= y * 32 + 31)))
		game->map[y][x] = '0';
	if (game->pos.x >= x * 32 && game->pos.x - 1 <= x * 32
		&& ((game->pos.y >= y * 32 && game->pos.y <= y * 32 + 31)
			|| (game->pos.y + 31 >= y * 32 && game->pos.y + 31 <= y * 32 + 31)))
		game->map[y][x] = '0';
}

void	sl_check_wall(t_info *game)
{
	int	len;
	int	x;
	int	y;

	len = ft_strlen(game->map[0]) - 1;
	y = -1;
	while (++y < game->size)
	{
		x = -1;
		while (++x < len)
			if (game->map[y][x] == '1')
				sl_check_wall_direc(game, x, y);
	}
}

void	sl_check_wall_direc(t_info *game, int x, int y)
{
	if (game->key.up)
		if (game->pos.y - MOV_SPEED <= y * 32 + 31
			&& game->pos.y - MOV_SPEED >= y * 32
			&& ((game->pos.x >= x * 32 && game->pos.x <= x * 32 + 31)
				|| (game->pos.x + 31 >= x * 32 && game->pos.x <= x * 32 + 31)))
			game->key.up = FALSE;
	if (game->key.down)
		if (game->pos.y + 31 + MOV_SPEED >= y * 32
			&& game->pos.y + 31 + MOV_SPEED <= y * 32 + 31
			&& ((game->pos.x >= x * 32 && game->pos.x <= x * 32 + 31)
				|| (game->pos.x + 31 >= x * 32
					&& game->pos.x <= x * 32 + 31)))
				game->key.down = FALSE;
	sl_check_wall_direct1(game, x, y);
}
