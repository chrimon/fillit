/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 00:02:06 by chmondev          #+#    #+#             */
/*   Updated: 2019/03/31 02:40:01 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_remove(char a, char **map, int size)
{
	int i;
	int x;

	x = 0;
	i = 0;
	while (x < size)
	{
		if (map[x][i] == a)
			map[x][i] = '.';
		i++;
		if (i == size)
		{
			i = 0;
			x++;
		}
	}
}

void	ft_read(char *str)
{
	int		fd;
	size_t	size;
	char	*file;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_putstr("File is not valid\n");
	else
	{
		size = ft_totsize(fd);
		file = ft_strnew(size + 1);
		fd = open(str, O_RDONLY);
		read(fd, file, size);
		ft_tet(file, size);
		free(file);
	}
}

void	printmap(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putstr("\n");
		i++;
	}
}

void	freelist(t_tetro *piece)
{
	t_tetro *tmp;

	tmp = NULL;
	while (piece)
	{
		tmp = piece;
		piece = piece->next;
		free(tmp);
	}
}

void	freemap(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		map[i] = 0;
		i++;
	}
	free(map);
}
