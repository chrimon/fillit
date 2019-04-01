/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:46:03 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/11 13:50:24 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *s, char c, int i)
{
	int a;

	a = i;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i - a);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i - 1] == c && s[i] != c) || (i == 0 && s[i] != c))
			j++;
		i++;
	}
	return (j);
}

static char	*ft_split(char const *s, char c, int *i)
{
	char	*m;
	int		h;

	h = 0;
	m = (char*)malloc(sizeof(char) * (ft_wordcount(s, c, *i) + 1));
	while (s[*i] != '\0' && s[*i] != c)
	{
		m[h] = s[*i];
		h++;
		(*i)++;
	}
	(*i) -= 1;
	m[h] = '\0';
	return (m);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**a;
	int			i;
	int			g;

	i = 0;
	g = 0;
	if (!s)
		return (0);
	if (!(a = (char**)malloc(sizeof(char*) * (ft_count(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			a[g] = ft_split(s, c, &i);
			g++;
		}
		i++;
	}
	a[g] = NULL;
	return (a);
}
