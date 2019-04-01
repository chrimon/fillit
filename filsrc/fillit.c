/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:16:38 by chmondev          #+#    #+#             */
/*   Updated: 2019/03/31 02:40:11 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(t_tetro *piece, char **map, t_map *map1)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (inbounds(piece, map1->size))
	{
		while (i < 4)
		{
			if (ft_isupper(map[piece->y[i]][piece->x[i]]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	place_tetri(t_tetro *piece, t_map *map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map->go[piece->y[i]][piece->x[i]] = piece->letter;
		i++;
	}
}

int		solve(t_tetro *piece, t_map *map)
{
	int		i;

	i = -1;
	if (!piece)
		return (1);
	while (++i < ((map->size - 1) * (map->size - 1)))
	{
		if (check(piece, map->go, map))
		{
			place_tetri(piece, map);
			printmap(map->go, map->size);
			ft_putchar('\n');
			if (solve(piece->next, map))
				return (1);
			else
			{
				ft_remove(piece->letter, map->go, map->size);
				transform(piece, map, 0);
				transform(piece->next, map, 7);
			}
		}
		else if (!transform(piece, map, 0))
			transform(piece, map, 7);
	}
	return (0);
}

void	start(t_tetro *piece, t_map *map)
{
	while (!solve(piece, map))
	{
		printmap(map->go, map->size);
		ft_plus_map(map);
		transform(piece, map, 1);
	}
	printmap(map->go, map->size);
	freemap(map->go, map->size);
	free(map);
}
