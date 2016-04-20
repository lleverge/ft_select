/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:50:00 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/20 19:19:18 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		myputchar(int c)
{
	return (write(2, &c, 1));
}

t_term	*ft_stock(t_term *termi, int i)
{
	static t_term *tmp;

	tmp = NULL;
	if (i == 0)
		tmp = termi;
	return (tmp);
}

int		check_size(t_term *termi)
{
	if (termi->nb_row - 2 < termi->count[1]
		|| termi->nb_col - 2 < termi->count[0])
	{
		ft_putendl_fd("Windows size too smtermi.", 2);
		return (0);
	}
	else
		return (1);
}

void	ft_resize(void)
{
	t_term			*termi;
	struct winsize	win;

	termi = NULL;
	termi = ft_stock(termi, 1);
	ioctl(0, TIOCGWINSZ, &win);
	termi->nb_col = win.ws_col;
	termi->nb_row = win.ws_row;
	check_size(termi);
}

void	count_col(t_term *termi)
{
	t_dblist	*tmp;

	termi->count[0] = termi->dblist->len;
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (tmp->len > termi->count[0])
			termi->count[0] = tmp->len;
		tmp = tmp->next;
	}
}
