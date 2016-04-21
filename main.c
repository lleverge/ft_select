/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:26:59 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/21 15:46:02 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_select(char **argv, t_term *termi)
{
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
	int		i;

	i = 0;
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
