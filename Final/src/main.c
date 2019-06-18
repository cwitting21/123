/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:35:07 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/17 18:58:55 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int ac, char **av)
{
	int			opt;
	int			fd;

	opt = 0;
	if (ac == 3 && ft_strncmp(av[1], "--options", 9) == 0)
		opt = av[1][9] - '0';
	if (ac == 2 || (opt > 0 && opt < 3))
	{
		if ((fd = open(opt > 0 ? av[2] : av[1], O_RDONLY)) < 0 ||
				!(fillit(fd, opt)) || close(fd))
			return (ft_error());
	}
	else
		ft_putstr("  usage: fillit [ --options1 | --options2 ] source_file\n");
	return (0);
}
