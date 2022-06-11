/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:11:38 by odessein          #+#    #+#             */
/*   Updated: 2022/06/06 19:14:28 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "sl.h"

void	sl_init_list_to_check(t_check *list_to_check)
{
	list_to_check->start = 0;
	list_to_check->exit = 0;
	list_to_check->collec = 0;
}

void	sl_fill_list(char c, t_check *list)
{
	if (c == 'P')
		list->start++;
	if (c == 'E')
		list->exit++;
	if (c == 'C')
		list->collec++;
}

t_bool	ft_check_line_wall(char *line)
{
	while (*line != '\n')
	{
		if (*line != '1')
			return (FALSE);
		line++;
	}
	return (TRUE);
}
