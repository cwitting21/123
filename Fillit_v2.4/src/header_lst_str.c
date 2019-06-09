/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_lst_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:29:19 by wmaykit           #+#    #+#             */
/*   Updated: 2019/05/15 15:11:39 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		header_lst_str(t_matrix **root, unsigned len)
{
	unsigned	i;
	t_matrix	*ptr;
	t_matrix    *begin;

	i = 1;
	ptr = *root;
	begin = ptr;
	while (i <= len)
	{
		if (!(ptr->right = newlst(*root, i++, 0, '@')))
			return (0);
		ptr->right->left = ptr;
		ptr->root = *root;
		ptr = ptr->right;
	}
	begin->left = ptr;
	ptr->right = begin;
	return (1);
}
