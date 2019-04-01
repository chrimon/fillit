/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:32:40 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/10 00:54:55 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*h;
	unsigned char	*g;

	i = -1;
	h = (unsigned char*)s;
	g = (unsigned char*)d;
	while (++i < n)
	{
		g[i] = h[i];
		if (g[i] == (unsigned char)c)
			return ((void*)&g[i + 1]);
	}
	return (NULL);
}
