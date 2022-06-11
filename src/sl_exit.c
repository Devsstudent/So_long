/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:58:57 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 21:01:28 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_finish(t_info *game, char *output)
{
	mlx_destroy_image(game->mlx.mlx, game->render);
	game->end = TRUE;
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
		game->img.back, 0, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.win, 2600 / 2, 1440 / 2,
		255, output);
}

void	sl_lose(t_info *game, char *output)
{
	t_list	*buff;

	while (game->list_t != NULL)
	{
		buff = game->list_t->next;
		free(game->list_t->content);
		free(game->list_t);
		game->list_t = buff;
	}
	mlx_destroy_image(game->mlx.mlx, game->render);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.back, 0, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.win,
		2600 / 2, 1440 / 2, 255, output);
	game->end = TRUE;
}
