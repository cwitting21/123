/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lst_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:42:21 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 18:33:03 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		new_lst_bot(t_matrix *ptr, t_matrix *root, int level)
{
	static int	i;
	static int	c;
	t_matrix	*new;

	if (c != level)
		i++;
	c = level;
	if (c == 1 && i > 1)
		i = 1;
	while (ptr->bot)
		ptr = ptr->bot;
	if (!(new = newlst(root, ptr->x, level, '@' + i)))
		return (0);
	ft_links(new, ptr);
	return (1);
}

static int		movebits(int figure, int key, unsigned edge)
{
	if (edge < 4)
	{
		if (key == 2)
			figure >>= 2;
		else if (key < 3)
			figure >>= 1;
	}
	else if (key < 4)
		figure >>= 1;
	return (figure);
}

unsigned		new_lst_set(t_matrix *root, int figure, int level, unsigned len)
{
	t_matrix	*ptr;
	unsigned	count;
	unsigned	key;

	key = 0;
	ptr = root->right;
	count = 1;
	while (figure)
	{
		if ((figure & 1) && key < 4)
			if (!(new_lst_bot(ptr, root, level)))
				return (0);
		figure = movebits(figure, key++, len);
		if (key == len)
			key = 0;
		ptr = ptr->root->right;
		count++;
		while (ptr->x != count && figure && ptr != root)
			ptr = ptr->right;
	}
	return (count - 1);
}
