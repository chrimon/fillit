/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:37:59 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/12 12:23:06 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*g;

	i = 0;
	if (s && f)
	{
		g = (char*)malloc(ft_strlen(s) + 1);
		if (g)
		{
			while (s[i] != '\0')
			{
				g[i] = (*f)(s[i]);
				i++;
			}
			g[i] = '\0';
			return (g);
		}
		return (NULL);
	}
	return (NULL);
}
