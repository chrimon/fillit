/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:15:34 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/10 01:39:23 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	int		i;
	int		j;
	int		g;

	i = 0;
	if (n[0] == 0)
		return ((char*)h);
	while (h[i] != '\0')
	{
		j = 0;
		while (n[j] == h[i + j])
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
