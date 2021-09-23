/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createphilo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:39:22 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/23 10:12:04 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_mallocthread(t_param *p)
{
	p->thread_id = malloc(sizeof(pthread_t) * p->philosophers_nb);
	if (!p->thread_id)
		return (-1);
	return (1);
}

int	ft_malloceat(t_param *p)
{
	int	i;

	i = -1;
	p->eat = malloc(sizeof(int) * p->philosophers_nb);
	if (!p->eat)
		return (-1);
	while (++i < p->philosophers_nb)
	{
		p->eat[i] = 0;
	}
	return (1);
}

int	ft_createphilo(t_param *p)
{
	int	checker;
	void	*v;
	pthread_t	id;

	p->i = -1;
	ft_timestart(p);
	ft_mallocthread(p);
	ft_malloceat(p);
	while (++p->i < p->philosophers_nb)
	{
		if (p->i % 2 == 0)
			checker = pthread_create(&p->thread_id[p->i], NULL, &ft_newphilo, (void *) p);
		if (checker != 0)
		{
			return (-1);
		}
		usleep(60);
	}
	p->i = -1;
	while (++p->i < p->philosophers_nb)
	{
		if (p->i % 2 == 1)
			checker = pthread_create(&p->thread_id[p->i], NULL, &ft_newphilo, (void *) p);
		if (checker != 0)
		{
			return (-1);
		}
		usleep(60);
	}
	pthread_t threadid;
	checker = pthread_create(&threadid, NULL, &ft_death, (void *) p);
	int	k = 0;
	p->dead = 0;
	while (1)
	{
		if (p->dead == 1)
			break;
		k++;
	}
	return (1);
}
