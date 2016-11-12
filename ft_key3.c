/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 14:32:46 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/12 10:15:05 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			move_right(t_term *termi)
{
	int			i;
	int			nb_col;
	int			nb_files_per_col;
	t_dblist	*tmp;

	if (termi->nb_col > max_size(termi) + 2)
	{
		tmp = termi->dblist;
		nb_col = termi->nb_col / (max_size(termi) + 2);
		nb_files_per_col = (list_size(termi) + 1) / nb_col;
		i = 0;
		while (tmp->line != 1)
			tmp = tmp->next;
		tmp->line = 0;
		while (nb_files_per_col-- + 1)
		{
			if (tmp->next == termi->dblist)
				break ;
			tmp = tmp->next;
		}
		tmp->line = 1;
	}
}

void			move_left(t_term *termi)
{
	int			i;
	int			nb_col;
	int			nb_files_per_col;
	t_dblist	*tmp;

	if (termi->nb_col > max_size(termi) + 2)
	{
		tmp = termi->dblist;
		nb_col = termi->nb_col / (max_size(termi) + 2);
		nb_files_per_col = (list_size(termi) + 1) / nb_col;
		i = 0;
		while (tmp->line != 1)
			tmp = tmp->next;
		tmp->line = 0;
		while (nb_files_per_col-- + 1)
		{
			if (tmp == termi->dblist)
				break ;
			tmp = tmp->prev;
		}
		tmp->line = 1;
	}
}
