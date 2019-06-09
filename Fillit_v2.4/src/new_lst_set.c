/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lst_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:42:21 by wmaykit           #+#    #+#             */
/*   Updated: 2019/05/26 13:56:13 by wmaykit          ###   ########.fr       */
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
		{
			//ft_putstr("***************************************\n");
			figure >>= 2;
		}
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

	//ft_putstr("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	key = 0;
	ptr = root->right;
	count = 1;
	while (figure)
	{
		if ((figure & 1) && key < 4)
			if (!(new_lst_bot(ptr, root, level)))
				return (0);
		figure = movebits(figure, key++, len);
		//if (key++ < 4)
		//	figure >>= 1;
		if (key == len)
			key = 0;
		ptr = ptr->root->right;
		count++;
		//ft_putnbr(count);
		//ft_putchar('\n');
		while (ptr->x != count && figure && ptr != root)
		{
			//ft_putstr("111111111111111111111111111111\n");
			ptr = ptr->right;
		}
	}
	//ft_putstr("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	return (count - 1);
}
