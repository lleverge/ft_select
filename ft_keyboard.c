/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 14:53:02 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/21 16:31:11 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_clear_screen(void)
{
	tputs(tgetstr("cl", NULL), 1, myputchar);
}

static void		move_up(t_term *termi)
{
	t_dblist	*tmp;

	tmp = termi->dblist;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	tmp->prev->line = 1;
}

static void		move_down(t_term *termi)
{
	t_dblist	*tmp;

	tmp = termi->dblist;
	while (tmp->line != 1)
		tmp = tmp->next;
	tmp->line = 0;
	tmp->next->line = 1;
}

static void		manage_key(t_term *termi, char *buffer[5])
{
	if (BUFFER == DOWN_KEY)
		move_down(termi);
	if (BUFFER == UP_KEY)
		move_up(termi);
	if (BUFFER == SPACE_KEY)
		ft_space(termi);
	if (BUFFER == HOME_KEY)
		go_start(termi);
	if (BUFFER == CRTL_A_KEY)
		selectall(termi);
	if (BUFFER == END_KEY)
		go_end(termi);
	if (BUFFER == TAB_KEY)
		ft_tab(termi);
}

int				ft_keyspot(t_term *termi)
{
	char	*buffer[5];

	ft_bzero(buffer, 5);
	read(0, buffer, 4);
	if (BUFFER == ESC_KEY)
		return (0);
	if (check_size(termi))
	{
		manage_key(termi, buffer);
		if (BUFFER == DEL_KEY || BUFFER == SUP_KEY)
		{
			if (!ft_delete(termi))
				return (0);
		}
		if (BUFFER == RET_KEY)
		{
			ft_ret(termi);
			return (0);
		}
		ft_clear_screen();
		print_list(termi);
	}
	return (1);
}