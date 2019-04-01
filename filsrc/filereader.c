/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filereader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:21:56 by chmondev          #+#    #+#             */
/*   Updated: 2019/03/31 02:39:48 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_totsize(int n)
{
	size_t	c;
	char	bu[1];

	c = 0;
	while (read(n, bu, 1))
		c++;
	close(n);
	return (c);
}

void	ft_verify(char **tet, int size)
{
	int		x;
	t_tetro	*new;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->size = 2;
	x = 0;
	while (x < size)
	{
		shapevalid(tet[x]);
		x++;
	}
	map->go = ft_makemap(map->size);
	new = mk_list(tet, size);
	transform(new, map, 1);
	start(new, map);
	freelist(new);
}

void	ft_tet(char *str, int size)
{
	char	**tet;
	int		i;
	int		m;
	int		f;
	int		l;

	tet = (char **)malloc(sizeof(char*) * ((size / 20) + 1));
	l = size % 20;
	i = (size / 20);
	m = 0;
	f = 0;
	if (!(i == l + 1) || i >= 26)
		ft_err();
	while (m < i)
	{
		tet[m] = ft_strnew(21);
		ft_strncpy(tet[m], &str[f], 20);
		tet[m][21] = '\0';
		m++;
		f += 21;
	}
	tet[m] = NULL;
	ft_verify(tet, i);
}
