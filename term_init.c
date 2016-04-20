/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:33:28 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/20 16:56:35 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_init_term(t_term *termi)
{
	struct winsize win;

	termi->enter = 0;
	if (tgetent(NULL, getenv("TERM")) < 1)
		return (0);
	if (tcgetattr(0, &(termi->term)) == -1)
		return (0);
	termi->term.c_lflag &= ~(ICANON | ECHO);
	termi->term.c_cc[VMIN] = 1;
	termi->term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	termi->nb_col = win.ws_col;
	termi->nb_row = win.ws_row;
	if (tcsetattr(0, 0, &(termi->term)) == -1)
		return (0);
	tputs(tgetstr("ti", NULL), 1, myputchar);
	tputs(tgetstr("vi", NULL), 1, myputchar);
	return (1);
}

int		ft_reset_term(t_term *termi)
{
	termi->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(termi->term)) == -1)
		return (0);
	tputs(tgetstr("te", NULL), 1, myputchar);
	tputs(tgetstr("ve", NULL), 1, myputchar);
	if (termi->enter)
		ft_putstr("ok\n");
	return (1);
}
