/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:06:25 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/12 12:25:59 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*g;
	size_t	i;

	i = 0;
	if (s)
	{
		g = (char*)malloc(len + 1);
		if (g)
		{
			while (s[start] != '\0' && i < len)
			{
				g[i] = s[start];
				i++;
				start++;
			}
			g[i] = '\0';
			return (g);
		}
		return (NULL);
	}
	return (NULL);
}
