/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:41:27 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/16 22:23:20 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t len;

	len = ft_strlen(needle);
	if ((haystack[0] == '\0' && needle[0] == '\0') || needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (ft_memcmp(haystack, needle, len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
