/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:08:14 by odessein          #+#    #+#             */
/*   Updated: 2022/06/10 21:21:12 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

char	**sl_parse(int ac, char **av, int *size_main)
{
	int		fd;
	int		size;
	char	**map;
	int		i;

	map = 0;
	size = 0;
	i = -1;
	if (!sl_check_arg(av, ac))
		return (NULL);
	if (!sl_nb_line(av[1], &size))
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (NULL);
	map = malloc(sizeof(*map) * (size + 1));
	if (!map)
		return (NULL);
	while (++i < size)
		map[i] = get_next_line(fd);
	*size_main = size;
	return (map);
}

t_bool	sl_nb_line(char *av, int *nb)
{
	int		fd;
	char	*line;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (FALSE);
	if (!fd)
		return (FALSE);
	while (line)
	{
		(*nb)++;
		free(line);
		line = get_next_line(fd);
	}
	return (TRUE);
}

t_bool	sl_check_ber(char *map_name)
{
	int	i;

	i = 0;
	while (map_name[i])
	{
		if (map_name[i] == '.' && map_name[i + 1] == 'b'
			&& map_name[i + 2] == 'e' && map_name[i + 3] == 'r'
			&& map_name[i + 4] == '\0')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	sl_check_arg(char **av, int ac)
{
	if (ac == 2 && sl_check_ber(av[1]))
	{
		return (TRUE);
		ft_printf("Error\nWrong argument");
	}
	return (FALSE);
}
