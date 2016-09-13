/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:10:13 by lleverge          #+#    #+#             */
/*   Updated: 2016/09/13 11:38:49 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	select_underline(char *str)
{
	tputs(tgetstr("us", NULL), 1, myputchar);
	tputs(tgetstr("so", NULL), 1, myputchar);
	ft_putstr_fd("\033[1;36m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("se", NULL), 1, myputchar);
	tputs(tgetstr("ue", NULL), 1, myputchar);
}

void	ft_manage_select(t_dblist *dblist)
{
	if (dblist->line == 1 && dblist->select == 1)
		select_underline(dblist->value);
	else if (dblist->line == 1)
		ft_underline(dblist->value);
	else if (dblist->select == 1)
		print_select(dblist->value);
	else
		ft_putendl_fd(dblist->value, 2);
}

void	print_select(char *str)
{
	tputs(tgetstr("so", NULL), 1, myputchar);
	ft_putstr_fd("\033[1;36m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("se", NULL), 1, myputchar);
}

void	ft_print(t_term *termi)
{
	int			i;
	int			max;
	t_dblist	*tmp;

	i = 1;
	max = -1;
	tmp = NULL;
	ft_manage_select(termi->dblist);
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		max = ft_op_display(termi, i, max);
		i++;
		ft_manage_select(tmp);
		tmp = tmp->next;
	}
}

void	ft_underline(char *str)
{
	tputs(tgetstr("us", NULL), 1, myputchar);
	ft_putstr_fd("\033[36m", 2);
	ft_putendl_fd(str, 2);
	ft_putstr_fd("\033[00m", 2);
	tputs(tgetstr("ue", NULL), 1, myputchar);
}
