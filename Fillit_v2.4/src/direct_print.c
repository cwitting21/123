/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:34:34 by cwitting          #+#    #+#             */
/*   Updated: 2019/06/10 19:09:57 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		printone(int key)
{
	if (key)
		ft_putchar('A');
	else
		ft_putchar('.');
}

int		direct_print(int *figures)
{
	int	edge;
	int	i;

	edge = 3;
	i = 1;
	if (figures[1] == O)
		edge = 2;
	else if (figures[1] == I || figures[1] == I1)
		edge = 4;
	while (i - 1 != edge * edge)
	{
		printone(figures[1] & 1);
		if (!(i++ % edge))
		{
			ft_putchar('\n');
			if (edge == 3)
				figures[1] >>= 1;
			else if (edge == 2)
				figures[1] >>= 2;
		}
		figures[1] >>= 1;
	}
	free(figures);
	return (1);
}
