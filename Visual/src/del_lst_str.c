/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 22:48:09 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/08 23:16:57 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*del_lst_str(t_matrix *del, int stage)
{
	if (!del->s && !del->root->s)
	{
		del->top->bot = del->bot;
		del->bot->top = del->top;
		del->s = stage;
	}
	return (del->right);
}
