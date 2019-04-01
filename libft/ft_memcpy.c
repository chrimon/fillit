/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 13:19:26 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/10 02:57:12 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t			i;
	unsigned char	*h;
	unsigned char	*g;

	i = -1;
	h = (unsigned char*)s;
	g = (unsigned char*)d;
	while (++i < n)
		g[i] = h[i];
	return (d);
}
