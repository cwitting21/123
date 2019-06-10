/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_subset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:35:57 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 15:19:21 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		del_subset(t_matrix *end, t_matrix *start, int stage)
{
	while (start != end)
	{
		del_lst_str(start, stage);
		start = start->set_next;
	}
}
