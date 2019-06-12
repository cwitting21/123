/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_lst_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 17:34:20 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 15:44:32 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_stack		*del_lst_stack(t_stack *lstdel)
{
	t_stack *out;

	out = lstdel;
	if (lstdel && lstdel->left)
		out = lstdel->left;
	if (lstdel)
	{
		lstdel->right->left = lstdel->left;
		lstdel->left->right = lstdel->right;
		lstdel = NULL;
	}
	return (out);
}
