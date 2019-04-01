/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:02:23 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/01 16:04:25 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	i = ft_strlen(s);
	j = -1;
	while (s[i] != (char)c)
	{
		if (i == 0)
			return (NULL);
		i--;
	}
	return ((char*)&s[i]);
}
