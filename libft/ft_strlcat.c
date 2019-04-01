/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:53:05 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/12 12:14:25 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *d, const char *s, size_t dsize)
{
	size_t	i;
	size_t	end;

	i = 0;
	if (dsize == 0)
		return (ft_strlen(s));
	while (d[i] && i < dsize)
		i++;
	end = i;
	while (s[i - end] && i < dsize - 1)
	{
		d[i] = s[i - end];
		i++;
	}
	if (end < dsize)
		d[i] = '\0';
	return (end + ft_strlen(s));
}
