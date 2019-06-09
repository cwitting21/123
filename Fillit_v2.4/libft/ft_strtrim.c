/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:36:23 by wmaykit           #+#    #+#             */
/*   Updated: 2019/04/16 22:24:04 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	end;
	size_t	front;

	if (s)
	{
		front = 0;
		while (ft_isblanks(s[front]))
			front++;
		if (s[front] == '\0')
			return (ft_strnew(0));
		end = ft_strlen(s);
		while (ft_isblanks(s[end - 1]))
			end--;
		res = ft_strsub(s, front, end - front);
		return (res);
	}
	return (NULL);
}
