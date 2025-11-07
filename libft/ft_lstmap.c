/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouarab <bbouarab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:23:10 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/07 08:29:44 by bbouarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp_old_list;
	t_list	*new_head;
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		del((void *)new);
		return (NULL);
	}
	new_head = new;
	temp_old_list = lst;
	while (temp_old_list->next != NULL)
	{
		new->content = f(temp_old_list->content);
		new->next = malloc(sizeof(t_list));
		if (new->next)
			return (NULL);
		temp_old_list = temp_old_list->next;
		new = new->next;
	}
	new->content = f(temp_old_list->content);
	new->next = NULL;
	return (new_head);
}
