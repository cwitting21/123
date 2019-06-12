/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:16:25 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/16 22:17:07 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	size;

	size = ft_strlen(src);
	if (size < len)
	{
		ft_memcpy(dst, src, size);
		ft_bzero(dst + size, len - size);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
