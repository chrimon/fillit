/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 01:18:43 by chmondev          #+#    #+#             */
/*   Updated: 2019/03/31 02:40:49 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_side(char *ptr)
{
	int		i;
	int		side;

	side = 0;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '#')
		{
			if (i && ptr[i - 1] == '#')
				side += 1;
			if (i + 1 < 20 && ptr[i + 1] == '#')
				side += 1;
			if (i + 5 < 20 && ptr[i + 5] == '#')
				side += 1;
			if (i - 5 > -1 && ptr[i - 5] == '#')
				side += 1;
		}
		i++;
	}
	if (side == 6 || side == 8)
		return (side);
	return (0);
}

int		twochars(char *ptr)
{
	size_t	x;
	int		ctr;
	int		per;

	per = 0;
	ctr = 0;
	x = -1;
	while (ptr[++x])
		if (ptr[x] == '#')
			ctr++;
	x = -1;
	while (ptr[++x])
		if (ptr[x] == '.')
			per++;
	if (ctr != 4 || per != 12)
		return (0);
	return (ctr);
}

int		shapevalid(char *ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
	{
		if (i + 1 % 5 == 0 && ptr[i] != '\n' && i != 0)
			ft_err();
		i++;
	}
	i = 0;
	if (!twochars(ptr) || !charvalid(ptr) || !ft_side(ptr))
		ft_err();
	return (1);
}

int		charvalid(char *ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '.' || ptr[i] == '#' || ptr[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}
