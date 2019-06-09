/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_dlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:36:26 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/09 17:21:50 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_matrix	*serch(t_matrix *knut, char name)
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
	int			res;

	if (!figures)
		return (1);
	if (!(guess = serch(knut, stack && stack->res ? stack->res->name + 1 : 'A')))
		return (0);
	if (!(stack = add_to_stack(stack, guess)))
	{
		ft_putstr("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		return (-1);
	}
	ft_putstr("\nvvvvvvvvvvvv    before [");
	ft_putnbr(figures);
	ft_putstr("]     vvvvvvvvvvvvvvvv\n");
	printmatrix(knut);
	del_cover(guess, figures);
	//ft_putstr("\nvvvvvvvvvvvv    before     vvvvvvvvvvvvvvvv\n");
	//printmatrix(knut);
	res = algorithm_dlx(knut, stack, figures - 1);
	if (!res)
	{
		recovery(guess, figures);
	/*	if (!select_next_guess(&stack, figures))
		{
			ft_putstr("\ngovno govno govno\n");
			return (0);
		}*/
		stack = del_lst_stack(stack);
		ft_putstr("\nvvvvvvvvvvvv    after [");
		ft_putnbr(figures);
		ft_putstr("]     vvvvvvvvvvvvvvvv\n");
		printmatrix(knut);
	}
	return (res);
}
