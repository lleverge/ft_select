/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:02:11 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/21 15:40:58 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_space(t_term *termi)
{
	t_dblist	*tmp;

	tmp = termi->dblist;
	while (tmp->line != 1)
		tmp = tmp->next;
	if (tmp->select == 0)
		tmp->select = 1;
	else
		tmp->select = 0;
	tmp->line = 0;
	tmp->next->line = 1;
}

void	go_end(t_term *termi)
{
	t_dblist	*tmp;

	tmp = termi->dblist;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	termi->dblist->prev->line = 1;
}

void	go_start(t_term *termi)
{
	t_dblist	*tmp;

	tmp = termi->dblist;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	termi->dblist->line = 1;
}

int		ft_delete(t_term *termi)
{
	t_dblist	*tmp;

	if (termi->dblist == termi->dblist->next)
	{
		free(termi->dblist);
		return (0);
	}
	tmp = termi->dblist;
	if (termi->dblist->line == 1)
		termi->dblist = tmp->next;
	else
	{
		while (tmp->line != 1)
			tmp = tmp->next;
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next->line = 1;
	free(tmp->value);
	free(tmp);
	count_col(termi);
	termi->count[1] -= 1;
	return (1);
}

void	ft_tab(t_term *termi)
{
	ft_space(termi);
}
