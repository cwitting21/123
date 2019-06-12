/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:03:01 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 22:51:09 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				solve(int *figures, int opt)
{
	t_stack		*res;
	t_matrix	*knut;

	knut = NULL;
	if (figures[0] == 1)
		return (direct_print(figures));
	if (!(res = backtracking(&knut, figures, opt)))
		return (0);
	printres(res);
	clean_matrix(&knut);
	del_stack(res, res->right);
	free(figures);
	return (1);
}
