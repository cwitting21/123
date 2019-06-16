/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 00:15:28 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/15 20:30:36 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_links(t_matrix *new, t_matrix *ptr)
{
	static int		i;
	static t_matrix	*prev;
	static t_matrix	*begin;

	if (i == 0)
		begin = new;
	ptr->bot = new;
	new->top = ptr;
	if (prev)
	{
		prev->right = new;
		new->left = prev;
		prev = new;
	}
	else
		prev = new;
	if (i++ == 3)
	{
		begin->left = new;
		new->right = begin;
		begin = NULL;
		prev = NULL;
		i = 0;
	}
}
