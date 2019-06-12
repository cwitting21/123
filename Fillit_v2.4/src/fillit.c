/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:00:23 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 18:54:18 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(const int fd, int opt)
{
	char	*read;
	int		i;
	int		*figures;

	i = 0;
	if (!(figures = identify(ft_read(fd, &read), &read)))
		return (0);
	if (opt == 1)
	{
		while (i < figures[0])
			ft_printbits(figures[++i], 32);
		return (1);
	}
	if (!(!solve(figures, opt)))
		return (0);
	return (1);
}
