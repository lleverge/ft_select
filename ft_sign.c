/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 17:59:56 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/21 19:00:50 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_sig_stop(void)
{
	t_term	*termi;
	char	cp[2];

	termi = NULL;
	termi = ft_stock(termi, 1);
	cp[0] = termi->term.c_cc[VSUSP];
	cp[1] = 0;
	termi->term.c_lflag |= ~(ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	ft_clear();
	tcsetattr(0, TCSADRAIN, &(termi->term));
	tputs(tgetstr("te", NULL), 1, myputchar);
	tputs(tgetstr("ve", NULL), 1, myputchar);
	ioctl(0, TIOCSTI, cp);
}

static void	ft_sig_cont(void)
{
	t_term *termi;

	termi = NULL;
	termi = ft_stock(termi, 1);
	termi->term.c_lflag &= ~(ICANON);
	termi->term.c_lflag &= ~(ECHO);
	termi->term.c_cc[VMIN] = 1;
	termi->term.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(termi->term));
	tputs(tgetstr("ti", NULL), 1, myputchar);
	tputs(tgetstr("vi", NULL), 1, myputchar);
	signal(SIGTSTP, manage_signal);
	ft_resize();
	check_size(termi);
}

static void	ft_interrupt(void)
{
	t_term *termi;

	termi = NULL;
	termi = ft_stock(termi, 1);
	ft_reset_term(termi);
	exit(0);
}

void		manage_signal(int i)
{
	if (i == SIGCONT)
		ft_sig_cont();
	else if (i == SIGTSTP)
		ft_sig_stop();
	else if (i == SIGWINCH)
		ft_resize();
	else
		ft_interrupt();
}

void		ft_signal(void)
{
	int i;

	i = 1;
	while (i < 32)
	{
		signal(i, manage_signal);
		i++;
	}
}
