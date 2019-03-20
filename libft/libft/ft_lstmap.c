/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:25:59 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:30 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*current;

	if (!lst || !f)
		return (NULL);
	current = f(lst);
	head = current;
	lst = lst->next;
	while (lst)
	{
		current->next = f(lst);
		current = current->next;
		lst = lst->next;
	}
	return (head);
}
