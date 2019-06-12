/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:13:02 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 21:14:33 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				buildmatrix(int *figures, t_matrix **knut, unsigned edge)
{
	//if (*knut)
	//	clean_matrix(*knut);
	if (!(*knut = newlst(NULL, 0, 0, 0)) || !(header_lst_str(knut, edge * edge))
			|| !(buildsets(knut, figures, edge)))
		return (0);
	sew(*knut);
	return (1);
}
