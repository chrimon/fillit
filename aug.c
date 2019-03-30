#include "../includes/fillit.h"

int	push_y_up(t_tetro *target)
{
	int i;
	int min;

	i = 0;
	min = 100;
	while (i < 4)
	{
		if (target->y[i] < min)
			min = target->y[i];
		i++;
	}
	i = 0;
	if (min != 100)
	{
		while (i < 4)
		{
			target->y[i] = target->y[i] - min;
			i++;
		}
		return (1);
	}
	return (0);
}

int	push_y_down(t_tetro *target, int size)
{
	int i;
	int min;

	i = -1;
	min = 10;
	while (++i < 4)
	{
		if (target->y[i] < min)
			min = target->y[i];
		if (target->y[i] + 1 >= size)
		{
			min = 100;
			break ;
		}
	}
	if (min != 100)
	{
		i = -1;
		while (++i < 4)
			target->y[i] = target->y[i] + 1;
		return (1);
	}
	return (0);
}

int	push_x_left(t_tetro *targ)
{
	int i;
	int min;
	int temp;

	i = -1;
	min = 100;
	while (++i < 4)
		if (targ->x[i] < min)
			min = targ->x[i];
	if (min != 100)
	{
		i = 0;
		while (i < 4)
		{
			temp = targ->x[i] - min;
			targ->x[i] = temp;
			i++;
		}
		return (1);
	}
	return (0);
}

int	push_x_right(t_tetro *targ, int size)
{
	int i;
	int max;

	i = -1;
	max = -1;
	while (++i < 4)
	{
		if (targ->x[i] > max)
			max = targ->x[i];
		if (targ->x[i] + 1 == size)
		{
			max = 100;
			break ;
		}
	}
	if (max != 100)
	{
		i = -1;
		while (++i < 4)
			targ->x[i] = targ->x[i] + 1;
		return (1);
	}
	return (0);
}

int	transform(t_tetro *targ, t_map *map, int on)
{
	if (!targ)
		return (0);
	else if (on == 7)
		push_all(targ);
	else if (on)
	{
		while (targ)
		{
			push_all(targ);
			targ = targ->next;
		}
		return (1);
	}
	else
	{
		if (!push_x_right(targ, map->size))
		{
			if (!push_y_down(targ, map->size))
				return (0);
			else
				push_x_left(targ);
		}
	}
	return (1);
}
