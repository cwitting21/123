/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_dlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:36:26 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 15:53:20 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** del_wrong = udalyaet oshibochnoe predpolozhenie
** scan - ischet ostalis li takie zhe bukvi
*/

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

/*
**static int		check(t_matrix *root, int figures, int len)
**{
**	t_matrix	*check;
**	t_matrix	*go_bot;
**	int			res;
**
**	res = len - figures;
**	check = root->right;
**	while (check != root)
**	{
**		go_bot = check->bot;
**		while (go_bot != check)
**		{
**			if (go_bot->name == 'A' + res)
**				res += 1;
**			if (res == len)
**				return (1);
**			go_bot = go_bot->bot;
**		}
**		check = check->right;
**	}
**	return (0);
**}
*/

int				algorithm_dlx(t_matrix *knut, t_stack *stack, int figures, int len)
{
	t_matrix	*guess;
	t_matrix	*tmp;
	int			res;

	if (figures == 0)
		return (1);
	if (!(guess = search(knut, 'A' + (len - figures)))
				/*|| !check(knut, figures, len)*/)
		return (0);
	del_cover(guess, figures);
	if (!(res = algorithm_dlx(knut, stack, figures - 1, len)))
	{
		recovery(guess, figures);
		tmp = del_wrong(guess, figures);
		if (!scan(knut, guess->name))
		{
			recover_wrong(guess->right->right->right, tmp, figures);
			return (0);
		}
		if(!(res = algorithm_dlx(knut, stack, figures, len)))
			recover_wrong(guess->right->right->right, tmp, figures);
	}
	else
		stack = add_to_stack(stack, guess);
	return (res);
}
