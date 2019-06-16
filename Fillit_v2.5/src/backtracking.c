/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 12:30:22 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/16 03:25:58 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		minsqrt(int *figures)
{
	int			res;
	int			i;
	int			check;

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

int				backtracking(t_dlx *box)
{
	box->edge = minsqrt(box->figures);
	if (!(box->res = new_lst_stack(NULL)) || !buildmatrix(box))
		return (0);
	while (!algorithm_dlx(box, box->figures[0]))
	{
		++box->edge;
		if (!buildmatrix(box))
			return (0);
	}
	return (1);
}
