/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 20:50:46 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 21:51:15 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		clean_col(t_matrix *top, t_matrix *bot)
{
	if (bot == top)
		return ;
	clean_col(top, bot->bot);
	free(bot);
	bot = NULL;
}

static void		clean_str(t_matrix *root, t_matrix *str)
{
	if (str == root)
		return ;
	clean_str(root, str->right);
	clean_col(str, str->bot);
	free(str);
	str = NULL;

}

void			clean_matrix(t_matrix **root)
{
	clean_str(*root, (*root)->right);
	free(*root);
	*root = NULL;
}
