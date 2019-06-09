/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 22:14:24 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/16 21:42:34 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			lead_sign(int sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

int					ft_atoi(const char *str)
{
	long int		res;
	int				sign;
	int				i;
	long int		check;

	sign = 1;
	res = 0;
	i = 0;
	check = 0;
	while (ft_isblanks(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		check = res;
		res = res * 10 + (str[i] - '0');
		if (res / 10 != check)
			return (lead_sign(sign));
		i++;
	}
	return ((int)res * sign);
}
