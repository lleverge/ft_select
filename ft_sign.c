/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:28:12 by lleverge          #+#    #+#             */
/*   Updated: 2016/07/26 17:32:51 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_resize2(int sig)
{
	(void)sig;
	ft_resize();
}

static void		ft_stop_term(int sig)
{
	t_term	*termi;
	char	cp[2];

	(void)sig;
	termi = NULL;
	termi = ft_stock(termi, 1);
	cp[0] = termi->term.c_cc[VSUSP];
	cp[1] = 0;
	termi->term.c_lflag |= (ICANON | ECHO);
	tcsetattr(termi->fd, TCSANOW, &(termi->term));
	tputs(tgetstr("cl", NULL), 1, myputchar);
	tputs(tgetstr("ve", NULL), 1, myputchar);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

static void		ft_restart_term(int sig)
{
	t_term	*termi;

	(void)sig;
	termi = NULL;
	termi = ft_stock(termi, 1);
	termi->term.c_lflag &= ~(ICANON | ECHO);
	termi->term.c_cc[VMIN] = 1;
	termi->term.c_cc[VTIME] = 0;
	tcsetattr(termi->fd, TCSANOW, &(termi->term));
	tputs(tgetstr("cl", NULL), 1, myputchar);
	tputs(tgetstr("vi", NULL), 1, myputchar);
	signal(SIGTSTP, ft_stop_term);
	ft_print(termi);
}

static void		ft_end_term(int sig)
{
	t_term *termi;

	(void)sig;
	termi = NULL;
	termi = ft_stock(termi, 1);
	tcsetattr(0, 0, &(termi->term));
	tputs(tgetstr("cl", NULL), 1, myputchar);
	tputs(tgetstr("ve", NULL), 1, myputchar);
	if (close(termi->fd) < 0)
		ft_putstr_fd("close", 2);
	exit(0);
}


void			ft_signal(void)
{
	signal(SIGWINCH, ft_resize2);
	signal(SIGTSTP, ft_stop_term);
	signal(SIGCONT, ft_restart_term);
	signal(SIGQUIT, ft_end_term);
	signal(SIGTERM, ft_end_term);
	signal(SIGINT, ft_end_term);
}
