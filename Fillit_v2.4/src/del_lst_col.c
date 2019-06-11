/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst_col.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 20:47:51 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/11 18:43:03 by cwitting         ###   ########.fr       */
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
