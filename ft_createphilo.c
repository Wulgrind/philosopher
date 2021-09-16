/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createphilo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:39:22 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/16 15:32:06 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_mallocthread(t_param *p)
{
	p->thread_id = malloc(sizeof(pthread_t) * p->philosophers_nb);
	if (p->thread_id)
		return (-1);
	return (1);
}

int	ft_createphilo(t_param *p)
{
	int	checker;
	void	*v;
	pthread_t	id;

	p->i = -1;
	ft_mallocthread(p);
	while (++p->i < p->philosophers_nb)
	{
		usleep(100000);
		checker = pthread_create(&p->thread_id[p->i], NULL, ft_newphilo, (void *) p);
		if (checker != 0)
		{
			return (-1);
		}
	}
	return (1);
}
