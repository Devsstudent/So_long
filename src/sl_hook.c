/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sl_hook.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: odessein <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/06 21:08:41 by odessein		  #+#	#+#			 */
/*   Updated: 2022/06/10 21:09:37 by odessein         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "sl.h"

int	sl_hook_press(int keycode, t_info *game)
{
	if (keycode == UP)
		game->key.up = TRUE;
	if (keycode == RIGHT)
		game->key.right = TRUE;
	if (keycode == LEFT)
		game->key.left = TRUE;
	if (keycode == DOWN)
		game->key.down = TRUE;
	sl_diagonal(game);
	return (0);
}

void	sl_diagonal(t_info *game)
{
	if (game->key.down && game->key.left)
		game->ship = game->img.ship_d_l;
	else if (game->key.down && game->key.right)
		game->ship = game->img.ship_d_r;
	else if (game->key.up && game->key.left)
		game->ship = game->img.ship_u_l;
	else if (game->key.up && game->key.right)
		game->ship = game->img.ship_u_r;
	else if (game->key.up)
		game->ship = game->img.ship_u;
	else if (game->key.down)
		game->ship = game->img.ship_d;
	else if (game->key.left)
		game->ship = game->img.ship_l;
	else if (game->key.right)
		game->ship = game->img.ship_r;
}

int	sl_hook_release(int keycode, t_info *game)
{
	if (keycode == ESCAPE)
	{
		sl_close(game);
		return (0);
	}
	if (keycode == UP)
		game->key.up = FALSE;
	if (keycode == RIGHT)
		game->key.right = FALSE;
	if (keycode == LEFT)
		game->key.left = FALSE;
	if (keycode == DOWN)
		game->key.down = FALSE;
	sl_diagonal(game);
	return (0);
}

int	sl_close(t_info *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	sl_backup_exit(game);
	sl_free_map(game->map, game->size);
	exit(1);
	return (0);
}

int	sl_hook(t_info *game)
{
	static int	i;

	if (game->end)
		return (0);
	if ((game->counter) % (4 * 32) == 0 && game->counter != 0)
		sl_replace_enemy(game);
	if (!sl_move_ship(game))
		return (0);
	if (!sl_check_coins_number(game))
		sl_backup_exit(game);
	sl_display_background(game);
	sl_display_enemy(game);
	sl_display_ship(game);
	if (game->enemy)
		sl_animate_enemy(game, i);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->render,
		game->center.x, game->center.y);
	sl_display_counter(game);
	i += 1;
	return (0);
}
