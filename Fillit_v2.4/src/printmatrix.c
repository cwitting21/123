/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 19:54:16 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 18:50:30 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			printheader(t_matrix *root)
{
	t_matrix		*start;

	start = root->right;
	while (start != root)
	{
		ft_putnbr(start->x);
		ft_putchar(' ');
		start = start->right;
	}
	ft_putchar('\n');
}

static unsigned		scan(t_matrix *root)
{
	t_matrix		*start;
	t_matrix		*up;
	unsigned		len_max;

	len_max = 0;
	up = root->right;
	while (up != root)
	{
		start = up->bot;
		while (start != up)
		{
			if (start->y > len_max)
				len_max = start->y;
			start = start->bot;
		}
		up = up->right;
	}
	return (len_max);
}

static void			printone(t_matrix *col, unsigned lvl)
{
	while (col->y < lvl && col->bot->name != '@')
		col = col->bot;
	if (col->y == lvl && col->name != '@')
	{
		ft_putstr("\033[01;32m");
		ft_putchar(col->name);
		ft_putstr("\033[00m");
		ft_putnbr(col->x);
	}
	else
		ft_putchar('.');
}

void				printmatrix(t_matrix *root)
{
	t_matrix		*start;
	unsigned		len_max;
	unsigned		lvl;
	int				i;

	lvl = 1;
	i = 1;
	printheader(root);
	start = root->right;
	len_max = scan(root);
	while (lvl <= len_max + 1)
	{

		if (start == root)
		{
			++lvl;
			ft_putchar('\n');
			start = start->right;
		}
		if (lvl <= len_max)
		{
			printone(start->bot, lvl);
			ft_putchar(' ');
		}
		i++;
		start = start->right;
	}
}
