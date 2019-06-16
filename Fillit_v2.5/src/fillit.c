/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:00:23 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/16 05:38:00 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		clean(t_matrix **root, int **figures)
{
	if (root)
	{
		clean_matrix(root);
		root = NULL;
	}
	if (figures)
	{
		free(*figures);
		*figures = NULL;
	}
	return (0);
}

static t_dlx	*new_box(int edge)
{
	t_dlx		*new;

	if (!(new = (t_dlx *)malloc(sizeof(t_dlx))))
		return (NULL);
	new->knut = NULL;
	new->res = NULL;
	new->figures = 0;
	new->equal = 0;
	new->edge = edge;
	return (new);
}

static int		options(t_dlx *box, int opt)
{
	t_matrix	*root;
	int			i;

	i = 0;
	root = NULL;
	box->edge = 5;
	if (opt == 1)
		while (i < box->figures[0])
			ft_printbits(box->figures[++i], 32);
	if (opt == 2)
	{
		if (!buildmatrix(box))
			return (clean(NULL, &box->figures));
		else
		{
			printmatrix(root);
			clean(&root, &box->figures);
		}
		free(box);
	}
	clean(NULL, &box->figures);
	return (1);
}

static int		clean_box(t_dlx **box)
{
	if (*box)
	{
		if ((*box)->figures)
			free((*box)->figures);
		if ((*box)->knut)
			clean_matrix(&(*box)->knut);
		if ((*box)->res)
			del_stack((*box)->res, (*box)->res->right);
		(*box)->figures = NULL;
		free(*box);
		*box = NULL;
	}
	return (0);
}

int				fillit(const int fd, int opt)
{
	char		*read;
	t_dlx		*box;

	read = NULL;
	if (!(box = new_box(0)) ||
			(!(box->figures = identify(ft_read(fd, &read), &read))))
		return (clean_box(&box));
	if (opt == 1 || opt == 2)
		return (options(NULL, opt));
	if (!solve(&box))
		return (clean_box(&box));
	return (1);
}
