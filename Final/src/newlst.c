/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:28:34 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/16 00:52:25 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*newlst(t_matrix *root, unsigned x, unsigned y, char name)
{
	t_matrix	*new;

	if (!(new = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	new->top = NULL;
	new->bot = NULL;
	new->right = NULL;
	new->left = NULL;
	if (!root)
		new->root = new;
	else
		new->root = root;
	new->x = x;
	new->y = y;
	new->name = name;
	return (new);
}
