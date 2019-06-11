/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_sets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:44:01 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 17:27:54 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		recovery_sets(t_matrix *rec, int stage)
{
	t_matrix	*string;
	t_matrix	*col;
	int			i;

	i = 0;
	while (i++ < 4)
	{
		col = rec->root->top;
		while (col != rec)
		{
			string = col->left;
			while (string != col)
				string = recovery_lst_str(string, stage);
			col = col->top;
		}
		recovery_lst_col(rec->root, stage);
		rec = rec->left;
	}
}
