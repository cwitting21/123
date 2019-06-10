/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_dlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:36:26 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/10 22:10:32 by cwitting         ###   ########.fr       */
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

static int		check(t_matrix *root, int figures, int len)
{
	t_matrix	*check;
	t_matrix	*go_bot;
	int			res;

	res = len - figures;
	check = root->right;
	while (check != root)
	{
		go_bot = check->bot;
		while (go_bot != check)
		{
			if (go_bot->name == 'A' + res)
				res += 1;
			if (res == len)
				return (1);
			go_bot = go_bot->bot;
		}
		check = check->right;
	}
	return (0);
}

int				algorithm_dlx(t_matrix *knut, t_stack *stack, int figures, int len)
{
	t_matrix	*guess;
	t_matrix	*tmp;
	int			res;

	if (figures == 0)
		return (1);
	if (!(guess = search(knut, stack && stack->res ? stack->res->name + 1 : 'A'))
				|| !check(knut, figures, len))
		return (0);
	if (!(stack = add_to_stack(stack, guess)))
		return (-1);
	//ft_putstr("\n\n");
	//ft_putnbr(figures);
	//ft_putstr("\n\n");
	//printmatrix(knut);
	del_cover(guess, figures);
	//ft_putstr("\nDEL COVER\n\n");
	//printmatrix(knut);
	/*if (!(res = algorithm_dlx(knut, stack, figures - 1)))
	{
		recovery(guess, figures);
		save = remove_wrong(guess->left, figures + 1000);
		if (!check(knut, stack->res->name))
		{
			stack = del_lst_stack(stack);
			recovery_wrong(save, guess->left, figures + 1000);
			return (0);																			}
		stack = del_lst_stack(stack);
		if (!(res = algorithm_dlx(knut, stack, figures)))
			recovery_wrong(save, guess->left, figures + 1000);*/
	if (!(res = algorithm_dlx(knut, stack, figures - 1, len)))
	{
		recovery(guess, figures);
		//stack = del_lst_stack(stack);
		tmp = del_wrong(guess, figures);
		//printmatrix(knut);
		if (!scan(knut, guess->name))
		{
			stack = del_lst_stack(stack);
			recover_wrong(guess->right->right->right, tmp, figures);
			return (0);
		}
		stack = del_lst_stack(stack);
	//	if(!(res = algorithm_dlx(knut, stack, figures, len)))
	//		recover_wrong(guess->right->right->right, tmp, figures);
		//recover_wrong(guess->right->right->right, tmp, figures);
		//if (!select_next_guess(&stack, figures))
		//{
		//	ft_putstr("\ngovno govno govno\n");
		//	return (0);
		//}
		//select_next_guess(&stack, figures);
		//select_next_guess(&stack, figures);

		//ft_putstr("\nvvvvvvvvvvvv    after [");
		//ft_putnbr(figures);
		//ft_putstr("]     vvvvvvvvvvvvvvvv\n");
	}
	return (res);
}
