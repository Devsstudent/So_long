/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mlx_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 21:16:53 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 21:19:13 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	sl_mlx_put_img_to_img(void *dest, void *src, t_pos pos)
{
	int		pos_in_dest;
	int		pos_in_src;
	int		len ;
	t_pos	pos_src;

	pos_src.y = 0;
	while (pos_src.y < 32)
	{
		len = 32 * (((t_img *) src)->bpp / 8);
		pos_in_dest = pos.x * (((t_img *) dest)->bpp / 8)
			+ pos.y * ((t_img *) dest)->size_line;
		pos_in_src = pos_src.y * ((t_img *) src)->size_line;
		ft_memcpy(((t_img *) dest)->data + pos_in_dest, ((t_img *) src)->data
			+ pos_in_src, len);
		(pos_src.y)++;
		(pos.y)++;
	}
}

void	sl_mlx_put_img_to_anim(void *dest, void *src, t_pos pos_src)
{
	int		pos_in_dest;
	t_pos	pos;
	int		pos_in_src;

	pos.x = 0;
	pos.y = 0;
	pos_src.y = 0;
	while (pos_src.y < 32)
	{
		pos_in_dest = pos.x * (((t_img *) dest)->bpp / 8)
			+ pos.y * ((t_img *) dest)->size_line;
		pos_in_src = pos_src.y * ((t_img *) src)->size_line
			+ pos_src.x * (((t_img *) src)->bpp / 8);
		ft_memcpy(((t_img *) dest)->data + pos_in_dest, ((t_img *) src)->data
			+ pos_in_src, 32 * ((((t_img *) src)->bpp / 8)));
		(pos_src.y)++;
		(pos.y)++;
	}
}
