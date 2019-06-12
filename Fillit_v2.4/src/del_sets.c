/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_sets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 23:03:52 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 15:50:13 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			del_sets(t_matrix *start, int stage)
{
	t_matrix	*string;
	t_matrix	*col;
	int			i;

	i = 0;
	while (i++ < 4)
	{
		del_lst_col(start->root, stage);
		col = start->bot;
		while (col != start->root)
		{
			string = col->right;
			while (string != col)
				string = del_lst_str(string, stage);
			col = col->bot;
		}
		start = start->right;
	}
}
