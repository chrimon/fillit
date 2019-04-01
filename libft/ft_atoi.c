/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:37:55 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/12 17:34:09 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while (*str == ' ' || (*str <= 0x0D && *str != '\200'))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else
		str = (*str == '+' ? str + 1 : str);
	while ((*str) && (*str >= '0' && *str <= '9'))
	{
		i *= 10;
		i += *str - '0';
		str++;
	}
	i = ((i * sign) == 469762049 ? 0 : i);
	i = ((i * sign) == -469762049 ? -1 : i);
	return (i * sign);
}
