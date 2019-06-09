/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_lst_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:57:15 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/07 15:03:21 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*recovery_lst_str(t_matrix *rec, int stage)
{
	if (rec->s == stage)
	{
		rec->top->bot = rec;
		rec->bot->top = rec;
		rec->s = 0;
	}
	return (rec->left);
}
