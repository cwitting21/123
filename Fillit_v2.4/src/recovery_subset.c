/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_subset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:05:22 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 17:25:07 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		recovery_subset(t_matrix *rec, int stage)
{
	t_matrix	*end;

	end = rec->set_next;
	while (rec != end)
	{
		recovery_lst_str(rec, stage);
		rec = rec->set_prev;
	}
}
