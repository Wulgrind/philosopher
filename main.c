/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:28:07 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/23 11:56:53 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_param	p;

	if (ac != 5 && ac != 6)
	{
		write (1, "Bad number of arguments\n", 24);
		return (1);
	}
	if (!ft_parsing(&p, av, ac))
	{
		write(1, "Wrong args", 10);
		return (1);
	}
	ft_forks(&p);
	ft_timestart(&p);
	ft_mallocthread(&p);
	ft_malloceat(&p);
	ft_createphilo(&p);
	return (0);
}
