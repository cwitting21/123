/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lst_subset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 00:27:53 by wmaykit           #+#    #+#             */
/*   Updated: 2019/05/16 01:34:16 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		go_down(t_matrix *one, t_matrix *two, t_matrix *three,
				t_matrix *four, int lvl)
{
	while (one->bot || two->bot || three->bot || four->bot)
	{
		if (one->y == lvl || two->y == lvl || three->y == lvl || four->y == lvl)
			return (1);
		if (one->bot)
			one = one->bot;
		if (two->bot)
			two = two->bot;
		if (three->bot)
			three = three->bot;
		if (four->bot)
			four = four->bot;
	}
	return (0);
}

static int		scan(t_matrix *root, int lvl, unsigned len, unsigned from)
{
	t_matrix	*one;
	t_matrix	*two;
	t_matrix	*three;
	t_matrix	*four;

	one = root->right;
	while (one->x != len)
		one = one->right;
	two = one;
	while (two->x != len * 2)
		two = two->right;
	three = two;
	while (three->x != len *3)
		three = three->right;
	four = three;
	while (four->x != len * 4)
		four = four->right;
	return (go_down(one, two, three, four, lvl, from));
}

int				new_lst_subset(t_matrix *root, int lvl, unsigned len)
{
	t_matrix	*ptr;
	t_matrix	*start;
	t_matrix	*end;
	unsigned	i;

	i = len * len;
	start = root->right;
	while (start->x != len)
		start = start->right;
	while (start->bot && start->y != (unsigned)lvl)
		start = start->bot;
	if (start->y == (unsigned)lvl)

	if (end->x == i)
		return (1);
}
