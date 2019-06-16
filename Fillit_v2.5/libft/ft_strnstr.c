/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:26:29 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/17 21:37:03 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t size;
	size_t lens;

	if ((h[0] == '\0' && n[0] == '\0') || n[0] == '\0')
		return ((char *)h);
	size = ft_strlen(n);
	if (size > len)
		return (NULL);
	lens = len - size + 1;
	while (*h != '\0' && lens-- != 0)
	{
		if (ft_memcmp(h, n, ft_strlen(n)) == 0)
			return ((char *)h);
		h++;
	}
	return (NULL);
}
