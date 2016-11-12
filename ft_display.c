/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:10:13 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/12 09:59:51 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	select_underline(char *str, int fd)
{
	tputs(tgetstr("us", NULL), 1, myputchar);
	tputs(tgetstr("so", NULL), 1, myputchar);
	ft_putstr_fd("\033[1;36m", fd);
	ft_putendl_fd(str, fd);
	ft_putstr_fd("\033[00m", fd);
	tputs(tgetstr("se", NULL), 1, myputchar);
	tputs(tgetstr("ue", NULL), 1, myputchar);
}

void	ft_manage_select(t_term *termi, t_dblist *dblist)
{
	if (dblist->line == 1 && dblist->select == 1)
		select_underline(dblist->value, termi->fd);
	else if (dblist->line == 1)
		ft_underline(dblist->value, termi->fd);
	else if (dblist->select == 1)
		print_select(dblist->value, termi->fd);
	else
		ft_putendl_fd(dblist->value, termi->fd);
}

void	print_select(char *str, int fd)
{
	tputs(tgetstr("so", NULL), 1, myputchar);
	ft_putstr_fd("\033[1;36m", fd);
	ft_putendl_fd(str, fd);
	ft_putstr_fd("\033[00m", fd);
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
	if ((termi->fd = open("/dev/tty", O_WRONLY)) == -1)
		exit(1);
	ft_manage_select(termi, termi->dblist);
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		max = ft_op_display(termi, i, max);
		i++;
		ft_manage_select(termi, tmp);
		tmp = tmp->next;
	}
}

void	ft_underline(char *str, int fd)
{
	tputs(tgetstr("us", NULL), 1, myputchar);
	ft_putstr_fd("\033[36m", fd);
	ft_putendl_fd(str, fd);
	ft_putstr_fd("\033[00m", fd);
	tputs(tgetstr("ue", NULL), 1, myputchar);
}
