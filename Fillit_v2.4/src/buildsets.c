/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildsets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 12:22:14 by wmaykit           #+#    #+#             */
/*   Updated: 2019/05/22 12:31:43 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				buildsets(t_matrix **root, int *figures, unsigned edge)
{
	int			i;
	int			lvl;
	unsigned	last;

	lvl = 1;
	i = 1;
	while (i <= figures[0])
	{
		if (!(last = new_lst_set(*root, figures[i], lvl, edge)) ||
				!(lvl = new_lst_subset(last, *root, lvl, edge)))
			return (0);
		ft_putstr("22222222222222222\n");
		i++;
	}
	ft_putstr("111111111111111111111111111111\n");
	return (1);
}
