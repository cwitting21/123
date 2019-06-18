/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:34:34 by cwitting          #+#    #+#             */
/*   Updated: 2019/06/16 03:46:04 by cwitting         ###   ########.fr       */
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

static void		clean(t_dlx **box)
{
	free((*box)->figures);
	free(*box);
	*box = NULL;
}

int				direct_print(t_dlx **box)
{
	int			edge;
	int			i;

	edge = 3;
	i = 1;
	if ((*box)->figures[1] == O)
		edge = 2;
	else if ((*box)->figures[1] == I || (*box)->figures[1] == I1)
		edge = 4;
	while (i - 1 != edge * edge)
	{
		printone((*box)->figures[1] & 1);
		if (!(i++ % edge))
		{
			ft_putchar('\n');
			if (edge == 3)
				(*box)->figures[1] >>= 1;
			else if (edge == 2)
				(*box)->figures[1] >>= 2;
		}
		(*box)->figures[1] >>= 1;
	}
	clean(box);
	return (1);
}
