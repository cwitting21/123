/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:46:04 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/18 17:38:32 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cleaner(void **trash, int index)
{
	if (trash)
	{
		while (index-- != 0)
			ft_memdel(trash + index);
		ft_memdel(trash);
	}
}
