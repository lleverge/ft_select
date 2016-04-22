/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:26:59 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/22 15:43:18 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_select(char **argv, t_term *termi)
{
	tputs(tgetstr("cr", NULL), 1, myputchar);
	tputs(tgetstr("sc", NULL), 1, myputchar);
	arg_in_list(argv, termi);
	count_col(termi);
	print_list(termi);
	check_size(termi);
	ft_stock(termi, 0);
	while (1)
	{
		if (!ft_keyspot(termi))
			return (0);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_term	termi;

	(void)argc;
	termi.dblist = NULL;
	if (!ft_init_term(&termi))
		return (-1);
	if (argc >= 2)
		ft_select(argv, &termi);
	if (!ft_reset_term(&termi))
		return (-1);
	return (0);
}
