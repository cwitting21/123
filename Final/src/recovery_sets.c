/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_sets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:44:01 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/15 20:09:49 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		recovery_sets(t_matrix *rec)
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
				string = recovery_lst_str(string);
			col = col->top;
		}
		recovery_lst_col(rec->root);
		rec = rec->left;
	}
}
