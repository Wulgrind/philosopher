/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newphilo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:51:39 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/16 15:32:47 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_forks(t_param *p)
{
	int	i;

	i = -1;
	p->fork = malloc(sizeof(pthread_mutex_t) * p->philosophers_nb);
	if (!p->fork)
		return (-1);
	while (++i < p->philosophers_nb)
	{
		pthread_mutex_init(&p->fork[i], NULL);
	}
	p->phil_max = p->philosophers_nb - 1;
	return (1);
}

void	*ft_newphilo(void *v)
{
	t_param	*c;
	t_param p;


	c = (t_param *) v;
	p = *c;
	return (NULL);
}
