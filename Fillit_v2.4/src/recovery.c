/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:24:21 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 14:49:39 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		recovery(t_matrix *rec, int stage)
{
	recovery_sets(rec->left, stage);
	recovery_subset(rec->set_prev, stage);
}
