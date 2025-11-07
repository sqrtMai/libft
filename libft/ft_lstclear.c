/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouarab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:18:41 by bbouarab          #+#    #+#             */
/*   Updated: 2025/11/07 08:19:45 by bbouarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t  ft_strlen(const char *s)
// {
//     size_t i;

//     i = 0;
//     while (s[i])
//         i++;
//     return (i);
// }

// char *ft_strdup(const char *src)
// {
//     char *copy;
//     size_t i;

//     i = 0;
//     copy = malloc(ft_strlen(src) + 1);
//     if (!copy)
//         return NULL;
//     while (src[i])
//     {
//         copy[i] = src[i];
//         i++;
//     }
//     copy[i] = 0;
//     return copy;
// }

// void ft_lstdelone(t_list *lst, void (*del)(void*))
// {
//     del(lst->content);
//     free(lst);
// }
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*real_temp;

	temp = *lst;
	while (temp->next != NULL)
	{
		real_temp = temp->next;
		del(temp->content);
		free(temp);
		temp = real_temp;
	}
	del(temp->content);
	free(temp);
	*lst = NULL;
}
