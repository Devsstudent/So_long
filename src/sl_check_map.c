/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:10:11 by odessein          #+#    #+#             */
/*   Updated: 2022/06/12 22:43:06 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

t_bool	sl_check_map(char **map, t_info *game, int size)
{
	t_check	list_to_check;

	if (!ft_check_rectangle(map, size))
		return (FALSE);
	sl_init_list_to_check(&list_to_check);
	if (!sl_check_component(map, size, &list_to_check))
		return (FALSE);
	if (!ft_check_wall(map, size))
		return (FALSE);
	if (list_to_check.start != 1 || list_to_check.exit < 1
		|| list_to_check.collec < 1)
	{
		ft_printf("Error\nUnexpected number of element in map");
		return (FALSE);
	}
	game->size = size;
	return (TRUE);
}

t_bool	ft_check_rectangle(char **map, int size)
{
	int	i;
	int	line_len;

	if (!(*map))
		return (FALSE);
	line_len = ft_strlen(*map);
	i = 0;
	while (i < size)
	{
		if ((size_t) line_len != ft_strlen(map[i]))
		{
			ft_printf("Error\nMap is not rectangular.");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	ft_check_wall(char **map, int size)
{
	int	size_l;
	int	i;

	i = 1;
	size_l = ft_strlen(*map) - 1;
	if (!ft_check_line_wall(*map) || !ft_check_line_wall(map[size - 1]))
	{
		ft_printf("Error\nMap not correctly surrounded by walls");
		return (FALSE);
	}
	while (i < size)
	{
		if (map[i][0] != '1' || map[i][size_l - 1] != '1')
		{
			ft_printf("Error\nMap not correctly surrounded by walls");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

t_bool	sl_check_component(char **map, int size, t_check *list)
{
	int		y;
	int		x;
	size_t	len;

	y = 1;
	len = ft_strlen(map[y]) - 1;
	while (y < size)
	{
		x = 0;
		while ((size_t) x < len)
		{
			if (map[y][x] != '1' && map[y][x] != 'P' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != '0' && map[y][x] != 'T')
			{
				ft_printf("Error\nA none expected element is present");
				return (FALSE);
			}
			sl_fill_list(map[y][x], list);
			x++;
		}
		y++;
	}
	return (TRUE);
}
