/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_lst_col.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:03:37 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 17:22:58 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	recovery_lst_col(t_matrix *rec, int stage)
{
	stage += 0;
	if (rec->s == stage)
	{
		rec->right->left = rec;
		rec->left->right = rec;
		rec->s = 0;
	}
}
