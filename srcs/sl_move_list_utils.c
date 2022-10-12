/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_move_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:19:03 by ojing-ha          #+#    #+#             */
/*   Updated: 2022/10/13 01:19:29 by ojing-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sl_list	*sl_lstnew(int content)
{
	t_sl_list	*list;

	list = malloc (sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	sl_lstadd_back(t_sl_list **lst, t_sl_list *new)
{
	t_sl_list	*lastlst;

	lastlst = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (lastlst)
	{
		if (lastlst->next == NULL)
		{
			lastlst->next = new;
			break ;
		}
		lastlst = lastlst->next;
	}
}