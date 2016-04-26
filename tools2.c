/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 16:54:37 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/22 19:18:48 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_op_display(t_term *termi, int file_max)
{
	int		i;
	int		j;
	int		col;
	t_dblist	*tmp;

	i = -1;
	j = 0;
	tmp = NULL;
	tmp = termi->dblist->next;
	col = max_col(termi, max_size(termi));
	if (list_size(termi) / col < termi->nb_row)
	{
		ft_manage_select(termi->dblist);
		while (tmp != termi->dblist)
		{
			j = -1;
			if ((i % (file_max / col)) == 0)
			{
				while (++j < file_max / col)
					tputs(tgetstr("up", NULL), 1, myputchar);
				tputs(tgetstr("nd", NULL), 1, myputchar);				
				tputs(tgetstr("nd", NULL), 1, myputchar);
			}
			ft_manage_select(tmp);
			tmp = tmp->next;
		}
	}
	else
		ft_putendl_fd("Too small", 2);
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
