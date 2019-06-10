/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lst_subset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 01:35:56 by wmaykit           #+#    #+#             */
/*   Updated: 2019/05/16 21:31:51 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check(t_matrix *ptr, unsigned len)
{
	t_matrix	*start;
	unsigned	i;
	int			i2;
	unsigned	begin;

	i = 2;
	i2 = 0;
	begin = len;
	while (ptr->x > len && i2 < 3)
	{
		i2++;
		ft_putnbr(ptr->x);
		begin = len * i++;
	}
	if (ptr->x == begin)
		return (1);
	start = ptr->right;
	while(start != ptr)
	{
		if (start->x == (len + begin) || start->x == (len * 2 + begin))
		{
			if (ptr->x > ((len * len) - (len * 3)))
				return (-1);
			return (1);
		}
		start = start->right;
	}
	return (0);
}

static t_matrix	*scan(t_matrix *root, int lvl)
{
	t_matrix	*ptr;
	t_matrix	*ptr_rt;
	int			key;

	key = 0;
	ptr = root->right;
	ptr_rt = ptr;
	while (key == 0 && ptr != root)
	{
		while (ptr->bot)
		{
			ptr = ptr->bot;
			if (ptr->y == (unsigned)lvl)
				key = 1;
		}
		ft_putstr("*******>");
		ft_putnbr(lvl);
		ft_putchar('|');
		ft_putnbr(ptr->y);
		ft_putchar('\n');
		ft_putstr("------>");
		ft_putchar(ptr->name);
		ft_putchar('\n');
		if (key != 1)
			ptr = ptr_rt->right;
		ptr_rt = ptr;
	}
	return(ptr);
}

int				new_lst_subset(t_matrix *root, int lvl, unsigned len)
{
	unsigned	i;
	t_matrix	*ptr;
	t_matrix	*neo;
	t_matrix	*new;

	i = 0;
	ptr = scan(root, lvl);
	while (!(check(ptr, len)))
	{
		ptr = scan(root, lvl++);
		ft_putendl("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa");
		while (i++ < 4)
		{
			neo = root->right;
			ft_putnbr(neo->x);
			while (neo->x - 1 != ptr->x)
			{
				ft_putendl("########################");
				neo = neo->right;
			}
			while (neo->bot)
			{
				ft_putendl("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1");
				neo = neo->bot;
			}
			if (!(new = newlst(root, neo->x - 1, lvl, ptr->name)))
				return (0);
			ft_links(new, neo);
			ptr = ptr->right;
		}
	}
	return (lvl);
}
