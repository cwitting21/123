/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 23:32:18 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/16 05:26:41 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		scan(int *figures)
{
	int			i;

	i = 0;
	while (++i < figures[0])
		if (figures[i] != figures[i + 1])
			return (0);
	return (1);
}

int				solve(t_dlx **box)
{
	(*box)->equal = scan((*box)->figures);
	if ((*box)->figures[0] == 1)
		return (direct_print(box));
	if (!(backtracking(*box)))
		return (0);
	printres(*box);
	clean_matrix(&(*box)->knut);
	del_stack((*box)->res, (*box)->res->right);
	free((*box)->figures);
	free(*box);
	return (1);
}
