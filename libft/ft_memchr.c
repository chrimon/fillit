/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:11:03 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/12 09:59:15 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*h;
	size_t			i;

	h = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (h[i] == (unsigned char)c)
			return ((void*)&h[i]);
		i++;
	}
	return (NULL);
}
