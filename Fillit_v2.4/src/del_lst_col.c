/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 20:47:51 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/07 14:31:01 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		del_lst_col(t_matrix *del, int stage)
{
	if (!del->s)
	{
		del->right->left = del->left;
		del->left->right = del->right;
		del->s = stage;
	}
}
