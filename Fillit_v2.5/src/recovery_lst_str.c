/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_lst_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmaykit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:57:15 by wmaykit           #+#    #+#             */
/*   Updated: 2019/06/15 20:09:08 by wmaykit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_matrix	*recovery_lst_str(t_matrix *rec)
{
	rec->top->bot = rec;
	rec->bot->top = rec;
	return (rec->left);
}
