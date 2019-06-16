/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 18:35:07 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/16 04:06:58 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		help(void)
{
	char		buf[51];
	int			fd;
	int			end;

	fd = open(".Makefile", O_RDONLY);
	while ((end = read(fd, buf, 50)))
	{
		buf[end] = '\0';
		ft_putstr(buf);
	}
	close(fd);
}

int				main(int ac, char **av)
{
	int			opt;
	int			fd;

	opt = 0;
	if (ac == 3 && ft_strncmp(av[1], "--options", 9) == 0)
		opt = av[1][9] - '0';
	if (opt > 3)
		opt = -1;
	if ((ac == 2 && ft_strcmp(av[1], "--help") != 0) || opt > 0)
	{
		if ((fd = open(opt > 0 ? av[2] : av[1], O_RDONLY)) < 0 ||
				!(fillit(fd, opt)) || close(fd))
			return (ft_error());
	}
	else if (ac == 2 && ft_strncmp(av[1], "--help", 9) == 0)
		help();
	else
	{
		ft_putstr("  usage: fillit [ --options1 | --options2 | --options3 ]");
		ft_putendl(" source_file\n\t fillit [--help]");
	}
	return (0);
}
