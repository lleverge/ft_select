/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 17:23:49 by lleverge          #+#    #+#             */
/*   Updated: 2016/07/26 17:30:16 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_check_size(t_term *termi)
{
	int	nb_col;
	int	nb_files_in_col;

	if (termi->nb_col > (max_size(termi) + 2))
	{
		nb_col = termi->nb_col / (max_size(termi) + 2);
		nb_files_in_col = (list_size(termi) + 1) / nb_col;
		if ((nb_files_in_col + 1) > (termi->nb_row - 1) ||
			nb_col < 1)
		{
			tputs(tgetstr("cl", NULL), 1, myputchar);
			ft_putendl_fd("Window size too small.", 2);
			return (0);
		}
		else
		{
			screen_clear();
			ft_print(termi);
		}
	}
	return (1);
}

void	ft_resize(void)
{
	t_term			*termi;
	struct winsize	win;

	termi = NULL;
	termi = ft_stock(termi, 1);
	screen_clear();
	ioctl(0, TIOCGWINSZ, &win);
	termi->nb_col = win.ws_col;
	termi->nb_row = win.ws_row;
	ft_check_size(termi);
}
