/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:43:11 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/11 20:28:40 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	g;

	i = 0;
	if (n[0] == 0)
		return ((char*)h);
	while (h[i] != '\0' && i < len)
	{
		j = 0;
		while (n[j] == h[i + j] && (i + j) < len)
		{
			if (n[j + 1] == '\0')
			{
				g = (i + j) - (ft_strlen(n) - 1);
				return ((char*)&h[g]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
