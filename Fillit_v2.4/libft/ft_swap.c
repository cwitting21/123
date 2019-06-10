/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:54:26 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/18 17:36:28 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_swap(void **a, void **b)
{
	void **c;

	if (a && b)
	{
		if (!(c = (void **)malloc(sizeof(void *) * 1)))
			return (NULL);
		*c = *a;
		*a = *b;
		*b = *c;
		ft_cleaner(c, 1);
		return (a);
	}
	return (NULL);
}
