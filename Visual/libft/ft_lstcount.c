/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:32:29 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/16 21:51:09 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list *lst)
{
	long int count;

	if (lst)
	{
		count = 0;
		while (lst)
		{
			count++;
			lst = lst->next;
		}
		return (count);
	}
	return (0);
}
