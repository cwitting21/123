/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildmatrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:13:02 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 15:43:40 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				buildmatrix(int *figures, t_matrix **knut, unsigned edge)
{
	if (!(*knut = newlst(NULL, 0, 0, 0)) || !(header_lst_str(knut, edge * edge))
			|| !(buildsets(knut, figures, edge)))
		return (0);
	sew(*knut);
	return (1);
}
