/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:33:42 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/20 17:57:20 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*first;

	if (!(first = (t_list*)malloc(sizeof(lst))))
		return (NULL);
	if (!lst)
		return (NULL);
	first = (*f)(lst);
	lst = lst->next;
	tmp = first;
	if (first)
	{
		while (lst)
		{
			tmp->next = (*f)(lst);
			lst = lst->next;
			tmp = tmp->next;
		}
		tmp->next = NULL;
		return (first);
	}
	return (NULL);
}
