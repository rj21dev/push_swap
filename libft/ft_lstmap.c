/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjada <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:15:20 by rjada             #+#    #+#             */
/*   Updated: 2021/10/10 19:06:52 by rjada            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*last;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	last = NULL;
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (!node)
			if (new_list)
				ft_lstclear(&new_list, del);
		if (last)
			last->next = node;
		if (!new_list)
			new_list = node;
		last = node;
		lst = lst->next;
	}
	return (new_list);
}
