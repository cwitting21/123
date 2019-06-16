/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:13:02 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/16 03:14:31 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				buildmatrix(t_dlx *box)
{
	if (box->knut)
		clean_matrix(&box->knut);
	if (!(box->knut = newlst(NULL, 0, 0, 0)) ||
			!(header_lst_str(&box->knut, box->edge * box->edge)) ||
			!(buildsets(&box->knut, box->figures, box->edge)))
		return (0);
	sew(box->knut);
	return (1);
}
