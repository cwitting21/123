/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:21:34 by cwitting          #+#    #+#             */
/*   Updated: 2019/06/16 06:16:24 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		del_stack(t_stack *end, t_stack *start)
{
	if (!end || !start || start == end)
	{
		if (end)
			free(end);
		return ;
	}
	del_stack(end, start->right);
	free(start);
	start = NULL;
}
