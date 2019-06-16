/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:07:39 by wmaykit           #+#    #+#             */
/*   Updated: 2019/05/20 17:56:14 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_stack		*add_to_stack(t_stack *stack, t_matrix *res)
{
	t_stack	*new;

	if (!(new = new_lst_stack(res)))
		return (NULL);
	if (stack->right)
	{
		stack->right->left = new;
		new->right = stack->right;
	}
	else
	{
		new->right = stack;
		stack->left = new;
	}
	stack->right = new;
	new->left = stack;
	return (new);
}
