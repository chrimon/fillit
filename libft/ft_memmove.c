/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:16:00 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/10 03:08:21 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (!((int *)dst > (int *)src && (int *)src + len > (int *)dst))
		ft_memcpy(dst, src, len);
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			*((char *)dst + i) = *((char *)src + i);
		}
	}
	return (dst);
}
