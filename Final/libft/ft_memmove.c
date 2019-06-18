/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:08:15 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/16 22:09:26 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (dst);
	if (src < dst)
		while ((int)--len >= 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
