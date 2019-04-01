/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 04:47:55 by chmondev          #+#    #+#             */
/*   Updated: 2019/03/31 02:23:06 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct			s_tetro
{
	char				letter;
	int					x[4];
	int					y[4];
	struct s_tetro		*next;
}						t_tetro;

typedef struct			s_map
{
	int					size;
	char				**go;
}						t_map;

void					ft_verify(char **tetro, int size);
void					ft_tetro(char *str, int size);
void					ft_read(char *str);
void					ft_use(void);
void					ft_err(void);
t_tetro					*mk_list(char **tetro, int size);
void					ft_double(char *str, t_tetro *link);
void					ft_coordinate(char **dptr, t_tetro *piece);
void					push(t_tetro *target);
void					freemap(char **map, int size);
void					freelist(t_tetro *piece);
void					printmap(char **map, int size);
void					ft_remove(char a, char **map, int size);
void					start(t_tetro *piece, t_map *map);
int						solve(t_tetro *piece, t_map *map);
void					place_tetri(t_tetro *piece, t_map *map);
int						check(t_tetro *piece, char **map, t_map *map1);
void					ft_tet(char *str, int size);
void					ft_verify(char **tet, int size);
size_t					ft_totsize(int n);
int						transform(t_tetro *targ, t_map *map, int on);
int						push_x_right(t_tetro *targ, int size);
int						push_x_left(t_tetro *targ);
int						push_y_down(t_tetro *targ, int size);
int						push_y_up(t_tetro *targ);
char					**ft_makemap(int size);
void					ft_plus_map(t_map *map);
int						inbounds(t_tetro *piece, int size);
int						ft_side(char *ptr);
int						twochars(char *ptr);
int						charvalid(char *ptr);
int						shapevalid(char *ptr);

#endif
