/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inbounds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:28:59 by chmondev          #+#    #+#             */
/*   Updated: 2019/03/31 02:40:21 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_makemap(int size)
{
	char	**map;
	int		i;

	map = (char**)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map[i] = (char*)ft_memalloc(size + 1);
		map[i] = ft_memset(map[i], 46, size);
		i++;
	}
	return (map);
}

void		ft_plus_map(t_map *map)
{
	freemap(map->go, map->size);
	map->size = map->size + 1;
	map->go = ft_makemap(map->size);
}

void		ft_err(void)
{
	ft_putstr("error\n");
	exit(0);
}

int			inbounds(t_tetro *piece, int size)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (piece->y[i] >= size)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (piece->x[i] >= size)
			return (0);
		i++;
	}
	return (1);
}
