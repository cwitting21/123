/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memсcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:26:38 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/16 22:25:16 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			ft_memcpy(dst, src, i + 1);
			return (dst + i + 1);
		}
		i++;
	}
	ft_memcpy(dst, src, n);
	return (NULL);
}
