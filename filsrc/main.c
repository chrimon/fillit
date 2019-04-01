/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:29:41 by chmondev          #+#    #+#             */
/*   Updated: 2019/03/31 02:40:40 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_use(void)
{
	ft_putstr("usage: ./fillit input file\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_read(argv[1]);
	else
		ft_use();
	return (0);
}
