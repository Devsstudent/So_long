/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_free_things.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:01:57 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 21:02:43 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

void	sl_free_map(char **map, int size)
{
	int	y;

	y = 0;
	while (y < size)
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	sl_backup_exit(t_info *game)
{
	t_list	*buff;
	t_pos	*tmp;

	while (game->list_e != NULL)
	{
		tmp = game->list_e->content;
		game->map[tmp->y][tmp->x] = 'E';
		buff = game->list_e->next;
		free(tmp);
		free(game->list_e);
		game->list_e = buff;
	}
}
