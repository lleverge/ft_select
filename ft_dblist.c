/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:29:05 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/20 18:43:05 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_dblist		*init_dblist(void)
{
	t_dblist	*tmp;

	tmp = (t_dblist *)malloc(sizeof(t_dblist));
	tmp->value = NULL;
	tmp->select = 0;
	tmp->line = 0;
	tmp->len = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_dblist		*fill_list(char *str)
{
	t_dblist	*tmp;

	tmp = init_dblist();
	tmp->value = ft_strdup(str);
	tmp->len = ft_strlen(tmp->value);
	return (tmp);
}

void			ft_add_link(t_term *termi, t_dblist *list)
{
	t_dblist	*tmp;

	if (termi->dblist == NULL)
	{
		list->prev = list;
		list->next = list;
		termi->dblist = list;
		list->line = 1;
	}
	else
	{
		tmp = termi->dblist->prev;
		tmp->next = list;
		list->next = termi->dblist;
		list->prev = tmp;
		termi->dblist->prev = list;
	}
}

void			arg_in_list(char **argv, t_term *termi)
{
	int			i;
	t_dblist	*tmp;

	i = 1;
	while (argv[i])
	{
		tmp = fill_list(argv[i]);
		ft_add_link(termi, tmp);
		i++;
	}
	termi->count[0] = i;
}
