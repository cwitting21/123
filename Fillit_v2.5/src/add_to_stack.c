/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:07:39 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/16 06:05:52 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_stack		*add_to_stack(t_stack *stack, t_matrix *res)
{
	t_stack	*new;

	if (!(new = new_lst_stack(res)))
		return (NULL);
	if (stack->left)
	{
		new->left = stack->left;
		stack->left->right = new;
	}
	else
	{
		new->left = stack;
		stack->right = new;
	}
	new->right = stack;
	stack->left = new;
	return (stack);
}
