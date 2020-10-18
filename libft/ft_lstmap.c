/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:49:11 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/26 16:41:01 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = (*f)(lst);
	new = ft_lstnew(tmp->content, tmp->content_size);
	lst = lst->next;
	start = new;
	while (lst != NULL)
	{
		tmp = (*f)(lst);
		new->next = ft_lstnew(tmp->content, tmp->content_size);
		lst = lst->next;
		new = new->next;
	}
	new = NULL;
	return (start);
}
