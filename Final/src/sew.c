/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sew.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 13:15:44 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/15 20:32:18 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				sew(t_matrix *knut)
{
	t_matrix		*start;
	t_matrix		*down;
	unsigned		num;

	start = knut->right;
	while (start != knut)
	{
		num = 0;
		down = start;
		while (down->bot)
		{
			++num;
			down = down->bot;
			down->root = start;
		}
		start->y = num;
		down->bot = start;
		start->top = down;
		start = start->right;
	}
}
