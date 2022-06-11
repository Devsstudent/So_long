/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sl_enemy.c                                         :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: odessein <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/10 20:53:53 by odessein		  #+#	#+#			 */
/*   Updated: 2022/06/10 22:27:34 by odessein         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "sl.h"

void	sl_setup_enemy(t_info *game, int x, int y)
{
	t_list	*new;
	t_pos	*coord;

	coord = (t_pos *) malloc(sizeof(t_pos));
	if (!coord)
		return ;
	coord->x = x;
	coord->y = y;
	new = ft_lstnew(coord);
	ft_lstadd_back(&game->list_t, new);
	game->map[y][x] = '0';
	game->enemy = FALSE;
}

void	sl_replace_enemy(t_info *game)
{
	t_list	**buff;
	t_list	**head;
	t_pos	*tmp;

	buff = malloc(sizeof(t_list));
	head = buff;
	*buff = game->list_t;
	while (*buff != NULL)
	{
		tmp = (*buff)->content;
		if (game->enemy)
			game->map[tmp->y][tmp->x] = 'W';
		else
			game->map[tmp->y][tmp->x] = 'T';
		*buff = (*buff)->next;
	}
	if (!game->enemy)
		game->enemy = TRUE;
	else
		game->enemy = FALSE;
	free(head);
}

t_bool	sl_check_enemy(t_info *game)
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
			if (game->map[y][x] == 'T')
				if (sl_check_enemy_direc(game, x, y))
					return (TRUE);
	}
	return (FALSE);
}

t_bool	sl_check_enemy_direc(t_info *game, int x, int y)
{
	if (game->pos.y + 32 >= y * 32 && game->pos.y + 32 <= y * 32 + 31
		&& ((game->pos.x >= x * 32 && game->pos.x <= x * 32 + 31)
			|| (game->pos.x + 31 >= x * 32 && game->pos.x <= x * 32 + 31)))
	{
		sl_lose(game, "YOU LOSE");
		return (TRUE);
	}
	if (game->pos.y - 1 >= y * 32 && game->pos.y - 1 <= y * 32 + 31
		&& ((game->pos.x >= x * 32 && game->pos.x <= x * 32 + 31)
			|| (game->pos.x + 31 >= x * 32 && game->pos.x <= x * 32 + 31)))
	{
		sl_lose(game, "YOU LOSE");
		return (TRUE);
	}
	if (sl_check_enemy_direc2(game, x, y))
	{
		return (TRUE);
	}
	return (FALSE);
}

t_bool	sl_check_enemy_direc2(t_info *game, int x, int y)
{
	if (game->pos.x + 32 >= x * 32 && game->pos.x + 32 <= x * 32 + 31
		&& ((game->pos.y >= y * 32 && game->pos.y <= y * 32 + 31)
			|| (game->pos.y + 31 >= y * 32 && game->pos.y + 31 <= y * 32 + 31)))
	{
		sl_lose(game, "YOU LOSE");
		return (TRUE);
	}
	if (game->pos.x - 1 >= x * 32 && game->pos.x - 1 <= x * 32 + 31
		&& ((game->pos.y >= y * 32 && game->pos.y <= y * 32 + 31)
			|| (game->pos.y + 31 >= y * 32 && game->pos.y + 31 <= y * 32 + 31)))
	{
		sl_lose(game, "YOU LOSE");
		return (TRUE);
	}
	return (FALSE);
}
