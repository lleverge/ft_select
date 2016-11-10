/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ret.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:14:51 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/10 12:01:35 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		deselectall(t_term *termi)
{
	t_dblist	*tmp;

	termi->dblist->select = 0;
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		tmp->select = 0;
		tmp = tmp->next;
	}
}

void		selectall(t_term *termi)
{
	t_dblist	*tmp;
	int			i;

	i = 0;
	if (termi->dblist->select == 0)
	{
		termi->dblist->select = 1;
		i = 1;
	}
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (tmp->select == 0)
		{
			tmp->select = 1;
			i = 1;
		}
		tmp = tmp->next;
	}
	if (!i)
		deselectall(termi);
}

void		print_res(t_term *termi)
{
	int		i;

	i = 0;
	while (termi->ret_tab[i])
	{
		ft_putstr(termi->ret_tab[i]);
		if (termi->ret_tab[i + 1])
			ft_putchar(32);
		i++;
	}
}

void		stock_res(t_term *termi)
{
	t_dblist	*tmp;
	int			i;

	i = 0;
	if (termi->dblist->select == 1)
	{
		termi->ret_tab[i] = ft_strdup(termi->dblist->value);
		i++;
	}
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (tmp->select == 1)
		{
			termi->ret_tab[i] = ft_strdup(tmp->value);
			i++;
		}
		tmp = tmp->next;
	}
	termi->ret_tab[i] = 0;
}

void		ft_ret(t_term *termi)
{
	t_dblist	*tmp;
	int			count;

	count = 0;
	termi->enter = 1;
	if (termi->dblist->select == 1)
		count++;
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (tmp->select == 1)
			count++;
		tmp = tmp->next;
	}
	termi->ret_tab = (char **)malloc(sizeof(char *) * (count + 1));
	stock_res(termi);
}
