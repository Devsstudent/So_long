/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: odessein <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/06/06 20:57:56 by odessein		  #+#	#+#			 */
/*   Updated: 2022/06/10 21:19:42 by odessein         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */
#include "sl.h"

t_bool	sl_move_ship(t_info *game)
{
	sl_check_wall(game);
	sl_check_coins(game);
	if (!sl_check_coins_number(game))
		if (sl_check_exit(game))
			return (FALSE);
	if (sl_check_enemy(game))
		return (FALSE);
	if (game->key.up)
		game->pos.y -= MOV_SPEED;
	if (game->key.down)
		game->pos.y += MOV_SPEED ;
	if (game->key.left)
		game->pos.x -= MOV_SPEED;
	if (game->key.right)
		game->pos.x += MOV_SPEED;
	if (game->key.up || game->key.down || game->key.left || game->key.right)
		game->counter++;
	return (TRUE);
}
