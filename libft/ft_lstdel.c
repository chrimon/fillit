/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:11:05 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/10 21:32:39 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*nxt;
	t_list	*rep;

	nxt = *alst;
	while (nxt != NULL)
	{
		(*del)(nxt->content, nxt->content_size);
		rep = nxt->next;
		free(nxt);
		nxt = rep;
	}
	*alst = NULL;
}
