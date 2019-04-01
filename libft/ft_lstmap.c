/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmondev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:03:05 by chmondev          #+#    #+#             */
/*   Updated: 2018/11/12 19:27:36 by chmondev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *p;
	t_list *new;

	if (!lst)
		return (NULL);
	if (!(new = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new = f(lst);
	p = new;
	while (lst->next)
	{
		p->next = f(lst->next);
		p = p->next;
		lst = lst->next;
	}
	return (new);
}
