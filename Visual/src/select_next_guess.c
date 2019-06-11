/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_next_guess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:47:11 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 20:54:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_matrix	*del_guess(t_matrix *guess, int stage)
{
	int			i;

	i = 0;
	guess = guess->set_next->set_next;
	del_lst_str(guess->set_next, stage);
	while (guess->x < guess->set_next->x)
	{
		del_lst_str(guess, stage);
		guess = guess->set_prev;
	}
	return (guess->set_next);
}

static void		recovery_guess(t_matrix *del, t_matrix *end, int stage)
{
	int 		i;

	i = 0;
	while (del != end)
	{
		recovery_lst_str(del, stage);
		del = del->set_next;
	}
}

static int		scan(t_matrix *root, char name)
{
	t_matrix	*start;

	start = root->right;
	while (start != root)
	{
		if (start->bot->name == name)
			return (1);
		start = start->right;
	}
	return (0);
}

int				select_next_guess(t_stack **stack, int figures)
{
	t_matrix	*save;
	int			key;

	key = 0;
	while ((*stack)->res && !key)
	{
		recovery((*stack)->res, figures);
		save = del_guess((*stack)->res, (*stack)->res->name);
		if (!(key = scan((*stack)->res->root->root, (*stack)->res->name)))
			recovery_guess(save, (*stack)->res->right->right->right, (*stack)->res->name);
		*stack = del_lst_stack((*stack));
	}
	return (!(*stack)->res && !key ? 0 : 1);
}
