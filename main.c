/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:26:59 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/21 19:02:35 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_select(char **argv, t_term *termi)
{
	ft_clear();
	arg_in_list(argv, termi);
	count_col(termi);
	print_list(termi);
	check_size(termi);
	ft_stock(termi, 0);
	while (42)
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
//	ft_signal();
	if (!ft_init_term(&termi))
		return (-1);
	if (argc >= 2)
		ft_select(argv, &termi);
	if (!ft_reset_term(&termi))
		return (-1);
	return (0);
}
