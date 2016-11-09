/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:26:59 by lleverge          #+#    #+#             */
/*   Updated: 2016/11/09 21:52:24 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_select(char **argv, t_term *termi)
{
	tputs(tgetstr("cl", NULL), 1, myputchar);
	tputs(tgetstr("sc", NULL), 1, myputchar);
	arg_in_list(argv, termi);
	count_col(termi);
	ft_print(termi);
	ft_check_size(termi);
	ft_stock(termi, 0);
	while (1)
	{
		if (!ft_keyspot(termi))
			return (0);
	}
	close(termi->fd);
	return (0);
}

int		main(int argc, char **argv)
{
	t_term	termi;

	(void)argc;
	signal(SIGINT, SIG_IGN);
	termi.dblist = NULL;
	ft_signal();
	if (!ft_init_termios(&termi))
		return (-1);
	if (argc >= 2)
		ft_select(argv, &termi);
	if (!ft_end_termios(&termi))
		return (-1);
	return (0);
}
