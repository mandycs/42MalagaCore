/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:30:33 by mancorte          #+#    #+#             */
/*   Updated: 2023/05/08 22:07:01 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(del)(void *))
{
	t_list	*lst_new;
	t_list	*position_new;
	t_list	*position_old;

	if (!lst)
		return (NULL);
	lst_new = ft_lstnew((*f)(lst->content));
	if (!lst_new)
		return (NULL);
	position_new = lst_new;
	position_old = lst->next;
	while (position_old)
	{
		position_new->next = ft_lstnew((*f)(position_old->content));
		if (!position_new)
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		position_new = position_new->next;
		position_old = position_old->next;
	}
	return (lst_new);
}
