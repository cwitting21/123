/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:34:36 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/17 20:34:21 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (s)
	{
		i = 0;
		subs = ft_strnew(len);
		while (len-- != 0 && subs)
			subs[i++] = s[start++];
		return (subs);
	}
	return (NULL);
}
