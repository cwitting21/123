/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sew.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:15:44 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/08 23:09:42 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			kastil(t_matrix *check)
{
	static t_matrix	*first;

	if (!check->set_prev)
		first = check;
	else if (!check->set_next)
	{
		first->set_prev = check;
		check->set_next = first;
	}
}

void				sew(t_matrix *knut)
{
	t_matrix		*start;
	t_matrix		*down;
	unsigned		num;

	start = knut->right;
	while (start != knut)
	{
		num = 0;
		down = start;
		while (down->bot)
		{
			++num;
			down = down->bot;
			kastil(down);
			down->root = start;
		}
		start->y = num;
		down->bot = start;
		start->top = down;
		start = start->right;
	}
}
