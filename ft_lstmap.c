/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mai <mai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:23:10 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/11 16:08:06 by mai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (!new)
	{
		del((void *)new);
		return (NULL);
	}
	new_head = new;
	while (lst->next != NULL)
	{
		new->content = f(lst->content);
		new->next = malloc(sizeof(t_list));
		if (!new->next)
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	new->content = f(lst->content);
	new->next = NULL;
	return (new_head);
}
