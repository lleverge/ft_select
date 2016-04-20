/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:26:59 by lleverge          #+#    #+#             */
/*   Updated: 2016/04/20 17:05:22 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(void)
{
	t_term	termi;
	int		i;

	i = 0;
	termi.dblist = NULL;
	ft_init_term(&termi);
	sleep(10);
	ft_reset_term(&termi);
	return (0);
}
