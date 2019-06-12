/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:13:26 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/18 17:27:21 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*frash;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	frash = new;
	lst = lst->next;
	while (lst)
	{
		frash->next = f(lst);
		lst = lst->next;
		frash = frash->next;
	}
	return (new);
}
