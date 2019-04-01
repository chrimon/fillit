/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 12:13:57 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/01 23:12:26 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numlen(long nbr)
{
	int	ctr;

	ctr = nbr < 0 ? 1 : 0;
	nbr = nbr < 0 ? nbr * -1 : nbr;
	while (nbr)
	{
		nbr /= 10;
		ctr++;
	}
	return (ctr);
}

char			*ft_itoa(int nbr)
{
	int		nlen;
	char	*ret;
	short	isneg;

	nlen = numlen(nbr);
	nlen = (nbr == 0 ? 1 : nlen);
	isneg = (nbr < 0 ? 1 : 0);
	nbr = (nbr < 0 ? nbr * -1 : nbr);
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	ret = (char*)malloc(nlen + 1);
	if (ret)
	{
		ret[nlen] = '\0';
		while (nlen--)
		{
			ret[nlen] = ((nbr % 10) + '0');
			nbr /= 10;
			if (!nlen && isneg)
				ret[0] = '-';
		}
		return (ret);
	}
	return (NULL);
}
