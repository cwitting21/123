/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lst_subset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 21:34:12 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/18 13:11:34 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_matrix		*go_to_last(t_matrix *root, unsigned last)
{
	t_matrix		*start;
	int				i;

	i = 0;
	start = root;
	while (start->x != last)
		start = start->right;
	while (start->bot)
		start = start->bot;
	while (i++ < 3)
		start = start->left;
	return (start);
}

static int			check(t_matrix *figure, unsigned len)
{
	t_matrix		*start;

	start = figure->right;
	if (!(figure->x % len))
	{
		if (figure->x > ((len * len) - len) ||
				figure->left->x > ((len * len) - len))
			return (-1);
		return (1);
	}
	while (start != figure)
	{
		if (!(start->x % len))
		{
			if (start->x > ((len * len) - len) ||
					figure->left->x > ((len * len) - len))
				return (-1);
			return (1);
		}
		start = start->right;
	}
	return (0);
}

static unsigned		countlen(t_matrix *start, unsigned len)
{
	unsigned		i;

	i = 1;
	if (len == 3 && start->right->x + len - 2 == start->right->right->x)
		return (3);
	if ((start->right->x + 1) == start->right->right->x && (start->right->x + 2)
			&& (start->x + 1) != start->right->x)
	{
		return ((start->x + len * 2) == start->left->x ||
				(start->x + (len * 2) + 1) == start->left->x ||
				(start->x + (len * 2) - 1) == start->left->x ? 2 : 3);
	}
	if (start->left->x - len <= start->x && start->left->x - 3 != start->x &&
			start->left->left->x - 2 != start->x)
		start = start->left;
	if ((start->right->right->x - len) <= start->x && start->left->x - 3 !=
			start->x && start->left->left->x - 2 != start->x)
		start = start->right->right;
	while (!(start->x % len) && i++ <= 4)
		start = start->right;
	i = 1;
	while (((start->x + i) - 1) % len)
		++i;
	return (i);
}

static t_matrix		*create(t_matrix *start, t_matrix *root, unsigned shift,
					int lvl)
{
	t_matrix		*find;
	unsigned		i;

	i = 0;
	while (i++ < 4)
	{
		find = root->right;
		while (find->x != start->x + shift && find != root)
			find = find->right;
		while (find->bot)
			find = find->bot;
		if (!(find->bot = newlst(root, start->x + shift, lvl, start->name)))
			return (NULL);
		ft_links(find->bot, find);
		start = start->right;
	}
	start = find->bot->right;
	return (start);
}

int					new_lst_subset(unsigned last, t_matrix *root, int lvl,
					unsigned edge)
{
	t_matrix		*start;
	int				i;

	i = 1;
	start = go_to_last(root, last);
	while (check(start, edge) != -1)
	{
		if (check(start, edge) == 0)
		{
			if (!(start = create(start, root, 1, lvl + i)))
				return (0);
		}
		else if (!(start = create(start, root, countlen(start, edge), lvl + i)))
			return (0);
		++i;
	}
	return (i + lvl);
}
