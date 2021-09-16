/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newphilo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:51:39 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/16 17:34:23 by qbrillai         ###   ########.fr       */
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

void	ft_routine2(t_param *p, int i, int eat)
{
	ft_putstr("Philosopher ");
	ft_putstr(num);
	ft_putstr(" is sleeping");
	usleep(p->ttsleep);
	ft_putstr("Philosopher ");
	ft_putstr(num);
	ft_putstr(" is thinking\n");
}

void	ft_routine(t_param *p, int i, int eat)
{
	char	*num;

	num = itoa(i);
		pthread_mutex_lock(p->fork[i]);
		ft_putstr("Philosopher ");
		ft_putstr(num);
		ft_putstr(" has taken a fork\n");
		if (i < phil_max)
			pthread_mutex_lock(p->fork[i + 1]);
		else
			pthread_mutex_lock(p->fork[0]);
	ft_putstr("Philosopher ");
	ft_putstr(num);
	ft_putstr(" has taken a fork\n";
	ft_putstr("Philosopher ");
	ft_putstr(num);
	ft_putstr(" is eating\n");
	usleep(p->tteat);
	ft_routine2(p, i, eat);
}

void	*ft_newphilo(void *v)
{
	t_param	*c;
	t_param p;
	int		i;
	
	c = (t_param *) v;
	p = *c;
	i = p->i
	while (1)
	{
		ft_routine(p, i, eat);
	}
	return (NULL);
}
