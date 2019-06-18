/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:33:26 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/16 22:15:58 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		s = ft_strnew(len1 + len2);
		if (s)
		{
			ft_strcpy(s, s1);
			ft_strlcat(s, s2, len1 + len2 + 1);
		}
		return (s);
	}
	return (NULL);
}
