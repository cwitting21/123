/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_dlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:36:26 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 22:50:51 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// del_wrong = udalyaet oshibochnoe predpolozhenie
// scan - ischet ostalis li takie zhe bukvi

int				scan(t_matrix *root, char name)
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

void		recover_wrong(t_matrix *end, t_matrix *start, int stage)
{
	while (start != end)
	{
		recovery_lst_str(start, 1000 + stage);
		start = start->set_next;
	}
	recovery_lst_str(start, 1000 + stage);
}

t_matrix	*del_wrong(t_matrix *guess, int stage)
{
	t_matrix	*tmp;

	tmp = guess->left->left;
	del_lst_str(guess->left, 1000 + stage);
	while (tmp->x < tmp->set_next->x || tmp->y < tmp->set_next->y)
	{
		del_lst_str(tmp, 1000 + stage);
		tmp = tmp->set_prev;
	}
	return (tmp->set_next);
}

static t_matrix	*search(t_matrix *knut, char name)
{
	t_matrix	*start;

	start = knut->right;
	while (start != knut)
	{
		if (start->bot->name == name)
			return(start->bot);
		start = start->right;
	}
	return (NULL);
}

int				algorithm_dlx(t_matrix *knut, t_stack *stack, int figures)
{
	t_matrix	*guess;
	t_matrix	*tmp;
	int			res;

	if (figures == 0)
		return (1);
	if (!(guess = search(knut, stack && stack->res ? stack->res->name + 1 : 'A')))
		return (0);
	if (!(stack = add_to_stack(stack, guess)))
		return (-1);
	ft_putstr("\n\n");
	ft_putnbr(figures);
	ft_putstr("\n\n");
	printmatrix(knut);
	del_cover(guess, figures);
	ft_putstr("\nDEL COVER\n\n");
	printmatrix(knut);
	while (!(res = algorithm_dlx(knut, stack, figures - 1)))
	//if (!res)
	{
		recovery(guess, figures);
		stack = del_lst_stack(stack);
		tmp = del_wrong(guess, figures);
		if (!scan(knut, guess->name))
		{
			recover_wrong(guess->right->right->right, tmp, figures);
			return (0);
		}
		/*if (!(res = algorithm_dlx(knut, stack, figures - 1)))
			return (0);*/
		//recover_wrong(guess->right->right->right, tmp, figures);
	/*	if (!select_next_guess(&stack, figures))
		{
			ft_putstr("\ngovno govno govno\n");
			return (0);
		}*/
		//select_next_guess(&stack, figures);
		//select_next_guess(&stack, figures);

		ft_putstr("\nvvvvvvvvvvvv    after [");
		ft_putnbr(figures);
		ft_putstr("]     vvvvvvvvvvvvvvvv\n");
		printmatrix(knut);
	}
	return (res);
}
