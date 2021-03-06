/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:50:00 by lleverge          #+#    #+#             */
/*   Updated: 2016/09/13 11:43:52 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		myputchar(int c)
{
	return (write(2, &c, 1));
}

void	get_screen_size(t_term *termi)
{
	struct winsize win;

	ioctl(0, TIOCGWINSZ, &win);
	termi->nb_col = win.ws_col;
	termi->nb_row = win.ws_row;
}

void	screen_clear(void)
{
	tputs(tgetstr("rc", NULL), 1, myputchar);
	tputs(tgetstr("cd", NULL), 1, myputchar);
}

t_term	*ft_stock(t_term *termi, int i)
{
	static t_term *tmp = NULL;

	if (i == 0)
		tmp = termi;
	return (tmp);
}

void	count_col(t_term *termi)
{
	t_dblist	*tmp;

	termi->count[COL] = termi->dblist->len;
	tmp = termi->dblist->next;
	while (tmp != termi->dblist)
	{
		if (tmp->len > termi->count[COL])
			termi->count[COL] = tmp->len;
		tmp = tmp->next;
	}
}
