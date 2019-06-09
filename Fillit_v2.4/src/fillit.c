/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:00:23 by wmaykit           #+#    #+#             */
/*   Updated: 2019/05/17 23:02:04 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fillit(const int fd, int opt)
{
	char	*read;
	int		i;
	int		*figures;

	if (!(figures = identify(ft_read(fd, &read), &read)) ||
			!solve(figures, opt))
		return (0);
	free(read);
	i = 0;
	if (opt == 1)
		while (i < figures[0])
			ft_printbits(figures[++i], 32);
	return (1);
}
