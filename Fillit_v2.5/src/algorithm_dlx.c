/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_dlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:36:26 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/16 03:36:16 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_matrix		*search(t_matrix *knut, char name)
{
	t_matrix		*start;
	t_matrix		*down;

	start = knut->right;
	while (start != knut)
	{
		down = start->bot;
		while (down != start)
		{
			if (down->name == name)
				return (down);
			down = down->bot;
		}
		start = start->right;
	}
	return (NULL);
}

static void			del_guess(t_matrix *guess)
{
	t_matrix		*start;

	start = guess->right;
	del_lst_str(guess);
	while (start != guess)
		start = del_lst_str(start);
}

static int			recovery_guess(t_matrix *guess)
{
	t_matrix		*start;

	start = guess->left;
	while (start != guess)
		start = recovery_lst_str(start);
	recovery_lst_str(guess);
	return (0);
}

int					algorithm_dlx(t_dlx *box, int stage)
{
	t_matrix		*guess;
	int				res;

	if (stage == 0)
		return (1);
	if (!(guess = search(box->knut, 'A' + (box->figures[0] - stage))))
		return (0);
	del_sets(guess);
	if (!(res = algorithm_dlx(box, stage - 1)))
	{
		recovery_sets(guess->left);
		del_guess(guess);
		if (!search(box->knut, 'A' + (box->figures[0] - stage)))
			return (recovery_guess(guess));
		if (!box->equal)
			res = algorithm_dlx(box, stage);
		recovery_guess(guess);
	}
	else
	{
		recovery_sets(guess->left);
		box->res = add_to_stack(box->res, guess);
	}
	return (res);
}
