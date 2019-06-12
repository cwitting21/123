/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 13:08:47 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/12 19:08:42 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			far(int **place, int len)
{
	int				*new;
	int				i;

	i = 1;
	if (!(new = (int *)malloc(sizeof(int) * len)))
		return (0);
	*place = new;
	*place[0] = len - 1;
	while (i < len)
	{
		new[i] = 0;
		++i;
	}
	return (1);
}

static int			last_step(int *b)
{
	int				check;
	int				i;

	i = -1;
	check = 0;
	while (i++ < 3 && !check)
	{
		if (!(*b ^ O) || !(*b ^ Z) || !(*b ^ Z1) || !(*b ^ Z2) || !(*b ^ Z3)
				|| !(*b ^ I) || !(*b ^ I1) || !(*b ^ T) || !(*b ^ T1)
				|| !(*b ^ T2) || !(*b ^ T3) || !(*b ^ L) || !(*b ^ L1)
				|| !(*b ^ L2) || !(*b ^ L3) || !(*b ^ L4) || !(*b ^ L5)
				|| !(*b ^ L6) || !(*b ^ L7))
			return (1);
		if (*b & 1)
			check++;
		*b >>= 1;
	}
	return (0);
}

static int			valid(int *bits)
{
	int				num;
	int				i;

	i = 0;
	num = 1;
	while (num <= bits[0])
	{
		if ((bits[num] & 24) != 24 && (bits[num] & 384) != 384 &&
				(bits[num] & 6144) != 6144)
		{
			while (i++ <= 3 && !(bits[num] & 15))
				bits[num] >>= 4;
			i = 0;
			if (!last_step(&bits[num]))
				return (0);
			++num;
		}
		else
			return (0);
	}
	return (1);
}

static int			convert(char *map, int *bits)
{
	int				i;

	i = 0;
	while (*map)
	{
		if (*map == '\n' && *(map - 1) == '\n')
			if (!(i % 8))
				++bits;
			else
				return (0);
		else if (*map == '#' || *map == '.' || *map == '\n')
		{
			if (*map != '\n')
				++i;
			else if (i % 4)
				return (0);
			*bits = bitmove(*bits, *map);
		}
		else
			return (0);
		++map;
	}
	return (1);
}

int					*identify(int len, char **read)
{
	int				*out;

	if (len <= 0 || ((len + 1) % 21 > 0) || !far(&out, (((len + 1) / 21) + 1)))
		return (0);
	if (!convert(*read, out + 1) || !valid(out))
	{
		if (out)
			free(out);
		free(*read);
		return (0);
	}
	free(*read);
	return (out);
}
