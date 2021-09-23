/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newphilo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:51:39 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/23 13:02:33 by qbrillai         ###   ########.fr       */
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
	pthread_mutex_init(&p->talk, NULL);
	p->phil_max = p->philosophers_nb - 1;
	return (1);
}

void	ft_routine2(t_param *p, int i)
{
	pthread_mutex_lock(&p->talk);
	printf("(%i) Philosopher %i is sleeping\n", ft_time(p), i + 1);
	pthread_mutex_unlock(&p->talk);
	usleep(p->tt_sleep * 1000);
	pthread_mutex_lock(&p->talk);
	printf("(%i) Philosopher %i is thinking\n", ft_time(p), i + 1);
	pthread_mutex_unlock(&p->talk);
}

void	ft_routine(t_param *p, int i)
{
	pthread_mutex_lock(&p->fork[i]);
	pthread_mutex_lock(&p->talk);
	printf("(%i) Philosopher %i has taken a fork\n", ft_time(p), i + 1);
	pthread_mutex_unlock(&p->talk);
	if (i < p->phil_max)
		pthread_mutex_lock(&p->fork[i + 1]);
	else
		pthread_mutex_lock(&p->fork[0]);
	pthread_mutex_lock(&p->talk);
	printf("(%i) Philosopher %i has taken a fork\n", ft_time(p), i + 1);
	pthread_mutex_unlock(&p->talk);
	pthread_mutex_lock(&p->talk);
	printf("(%i) Philosopher %i is eating\n", ft_time(p), i + 1);
	pthread_mutex_unlock(&p->talk);
	ft_eat(p, i);
	usleep(p->tt_eat * 1000);
	pthread_mutex_unlock(&p->fork[i]);
	if (i < p->phil_max)
		pthread_mutex_unlock(&p->fork[i + 1]);
	else
		pthread_mutex_unlock(&p->fork[0]);
	ft_routine2(p, i);
}

void	*ft_newphilo(void *v)
{
	t_param	*c;
	t_param	p;
	int		i;

	c = (t_param *) v;
	p = *c;
	i = p.i;
	ft_eat(&p, i);
	while (1)
	{
		ft_routine(c, i);
	}
	return (NULL);
}
