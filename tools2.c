/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 16:54:37 by lleverge          #+#    #+#             */
/*   Updated: 2016/05/02 14:29:47 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_op_display(t_term *termi, int i, int max)
{
	int		nb_col;
	int		nb_files_in_col;
	int		j;

	j = 0;
	nb_col = termi->nb_col / (max_size(termi) + 2);
	nb_files_in_col = (list_size(termi) + 1) / (nb_col - 1);
	if (i % (nb_files_in_col + 1) == 0)
	{
		tputs(tgetstr("rc", NULL), 1, myputchar);
		max += (max_size(termi) + 2);
	}
	while (j++ <= max)
		tputs(tgetstr("nd", NULL), 1, myputchar);
	return (max);
}

int				strlenint(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				max_col(t_term *termi, int max)
{
	int		res;

	res = termi->nb_col / (int)max;
	return (res);
}

int				list_size(t_term *termi)
{
	t_dblist    *tmp;
	int			size;

	size = 1;
	tmp = NULL;
	tmp = termi->dblist->next;
    while (tmp != termi->dblist)
    {
		size++;
        tmp = tmp->next;
    }
    return (size);
}

int				max_size(t_term *termi)
{
	t_dblist	*tmp;
	int			max_len;

	tmp = NULL;
	max_len = strlenint(termi->dblist->value);
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (strlenint(tmp->value) > max_len)
			max_len = strlenint(tmp->value);
		tmp = tmp->next;
	}
	return (max_len);
}
