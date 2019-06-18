/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 23:19:06 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 18:30:29 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(const int fd, char **x)
{
	int		len;
	char	buf[547];

	len = 0;
	len = read(fd, &buf, 546);
	if (len <= 0 || !(*x = ft_strsub(buf, 0, len)))
		return (-1);
	return (len);
}
