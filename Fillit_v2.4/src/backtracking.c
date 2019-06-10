/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:30:22 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 20:37:01 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		minsqrt(int *figures)
{
	int	res;
	int	i;
	int	check;

	i = 0;
	check = 0;
	while ((res = ft_sqrt(figures[0] * 4 + i)) == 0)
		++i;
	i = 0;
	while (i++ < figures[0])
		if (res == 3 && (figures[i] == I || figures[i] == I1))
				check = 1;
	return (res + check);
}

t_stack		*backtracking(t_matrix **knut, int *figures, int opt)
{
	t_stack		*stack;
	t_matrix	*test;
	t_matrix    *test1;
	unsigned	edge;
	int			i;

	i = 1;
	edge = minsqrt(figures);
	if (!buildmatrix(figures, knut, edge) || !(stack = new_lst_stack(NULL)))
		return (NULL);
	stack->edge = edge;
	if (opt == 2 || opt == 3)
	{
		printmatrix(*knut);
		test = (*knut)->right->top;
		test1 = test->set_prev;
		while (test1 && test != test1)
		{
			ft_putchar(test1->name);
			ft_putchar('[');
			ft_putnbr(test1->x);
			ft_putchar(']');
			ft_putchar(' ');
			test1 = test1->set_prev;
			if (test1 == NULL)
			{
				ft_putstr("\n\n");
				ft_putstr("fack fack fack fack fack fack fack fack fack");
				ft_putstr("\n\n");
			}
		}
		ft_putstr("\n\n");
		ft_putstr("end");
		ft_putstr("\n");
		return (NULL);
	}
	else
		while (!algorithm_dlx(*knut, stack, figures[0]))
		{
			if (!buildmatrix(figures, knut, ++edge))
				return (NULL);
			stack->edge = edge;
		}
	return (stack);
}
