/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:55:51 by ccarole           #+#    #+#             */
/*   Updated: 2019/04/25 18:08:51 by ccarole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst_new;

	if (!(lst_new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		lst_new->content = NULL;
		lst_new->content_size = 0;
	}
	else
	{
		if (!(lst_new->content = (void*)malloc(sizeof(void) * content_size)))
			return (NULL);
		ft_memmove(lst_new->content, content, content_size);
		lst_new->content_size = content_size;
	}
	lst_new->next = NULL;
	return (lst_new);
}
