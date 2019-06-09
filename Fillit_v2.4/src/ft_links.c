/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_links.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 00:15:28 by wmaykit           #+#    #+#             */
/*   Updated: 2019/05/25 20:26:05 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			link_set(t_matrix *new)
{
	static char		name;
	static t_matrix *start;
	static t_matrix *prev;

	if (name && name == new->name)
	{
		start->set_next = new;
		new->set_prev = start;
		start = new;
	}
	else 
	{
		if (prev && start->name + 1 == new->name)
		{
			prev->set_prev = start;
			start->set_next = prev;
		}
		prev = new;
		start = new;
		name = new->name;
	}
}

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
	link_set(new);
}
