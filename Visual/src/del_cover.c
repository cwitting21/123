/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:25:28 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 19:06:12 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		del_cover(t_matrix *start, int stage)
{
	del_subset(start, start->set_next->set_next->set_next->set_next, stage);
	del_sets(start, stage);
}
