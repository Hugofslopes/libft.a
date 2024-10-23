/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:13:25 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/23 17:17:13 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_node;

	if (!lst || !f)
		return (NULL);
	new_node = ft_lstnew(f(lst->content));
	if (!new_node)
	{
		del(new_node->content);
        free(new_node);
        return (NULL);
        return (NULL);
	}
	new_node->next = ft_lstmap(lst->next, f, del);
	if (!new_node->next)
	{
		del(new_node->content);
        free(new_node);
        return (NULL);
	}
    return (new_node);
}
