/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:58:48 by chmondev          #+#    #+#             */
/*   Updated: 2018/09/28 18:19:41 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*h;
	size_t			i;

	i = 0;
	h = (unsigned char*)b;
	if (len == 0)
		return (b);
	while (len--)
	{
		h[i] = (unsigned char)c;
		if (len)
			i++;
	}
	return (b);
}
