/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:51:28 by wmaykit           #+#    #+#             */
/*   Updated: 2019/05/15 22:12:28 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		printone(t_matrix *col, unsigned level)
{
	t_matrix *bot;

	bot = col->bot;
	while (bot && bot->bot && bot != col && bot->y != level)
		bot = bot->bot;
	if (bot && bot->y == level)
	{
		ft_putchar(bot->name);
		ft_putnbr(bot->x);
	}
	else
		ft_putchar('.');
}

static void		printheader(t_matrix *root)
{
	t_matrix	*ptr;

	ptr = root->right;
	while (ptr != root)
	{
		ft_putnbr(ptr->x);
		ptr = ptr->right;
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

void	printmatrix(t_matrix *root, unsigned level)
{
	t_matrix	*end;
	t_matrix	*start;
	unsigned	i;

	i = 1;
	end = root->right;
	start = root;
	printheader(root);
	while (i != level + 1)
	{
		while (end != start)
		{
			printone(end, i);
			end = end->right;
			if (end->x / 10)
				ft_putchar(' ');
			ft_putchar(' ');
		}
		ft_putchar('\n');
		end = root->right;
		++i;
	}
}
