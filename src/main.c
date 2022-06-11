/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:48:08 by odessein          #+#    #+#             */
/*   Updated: 2022/06/06 19:49:07 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

int	main(int ac, char **av)
{
	char	**map;
	t_info	game;
	int		size;

	map = sl_parse(ac, av, &size);
	if (!map)
		return (0);
	if (size < 3)
	{
		ft_printf("Error\nNot a valid path");
		return (0);
	}
	if (!sl_check_map(map, &game, size))
	{
		sl_free_map(map, size);
		return (0);
	}
	game.map = map;
	if (!sl_game(&game))
	{
		ft_printf("Error\nLoading Image or Window Creation Failed");
		return (0);
	}
}
