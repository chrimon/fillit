#include "../includes/fillit.h"

void	push(t_tetro *target)
{
	push_y_up(target);
	push_x_left(target);
}

void	ft_coordinate(char **dptr, t_tetro *piece)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (y < 4)
	{
		if (dptr[y][x] == '#')
		{
			piece->y[i] = y;
			piece->x[i] = x;
			i++;
		}
		x++;
		if (x == 4)
		{
			x = 0;
			y++;
		}
	}
}

void	ft_double(char *str, t_tetro *link)
{
	char	**ptr;
	int		x;
	int		ctr;

	ctr = 0;
	x = 0;
	ptr = ft_memalloc(sizeof(char*) * 4);
	while (x < 4)
	{
		ptr[x] = ft_strnew(4);
		ft_strncpy(ptr[x], &str[ctr], 4);
		ctr += 5;
		x++;
	}
	ft_coordiante(ptr, link);
	freemap(ptr, 4);
}

t_tetro	*mk_list(char **tetro, int size)
{
	t_tetro		*new;
	t_tetro		*buffer;
	int			i;

	i = 0;
	new = (t_tetro*)malloc(sizeof(t_tetro));
	buffer = new;
	while (i < size)
	{
		ft_double(tetro[i], new);
		new->letter = 'A' + i;
		if (i + 1 == size)
		{
			new->next = 0;
			break ;
		}
		else
			new->next = (t_tetro*)malloc(sizeof(t_tetro));
		new = new->next;
		i++;
	}
	freemap(tetro, size);
	return (buffer);
}
