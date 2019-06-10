/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lst_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:42:21 by wmaykit           #+#    #+#             */
/*   Updated: 2019/05/15 19:02:22 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		new_lst_set(t_matrix *root, int	figure, int level, unsigned len)
{
	t_matrix	*ptr;
	t_matrix    *prev;
	t_matrix	*new;
	unsigned	count;
	unsigned	key;
	int			len2;

	key = 0;
	ptr = root->right;
	len2 = len;
	count = 1;
	while (figure)
	{
		if (figure & 1)
		{
			while (ptr->bot)
				ptr = ptr->bot;
			if (!(new = newlst(root, (ptr->top) ? ptr->top->x : ptr->x, level, '@' + level)))
				return (0);
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
		}
		if (key++ < len)
			figure >>= 1;
		if (key == len)
			len +=len2;
		ptr = ptr->root;
		count++;
		while (ptr->x != count)
			ptr = ptr->right;
	}
	return (1);
}
