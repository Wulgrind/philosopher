/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:25:29 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/22 15:49:30 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_eat(t_param *p, int i)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	p->eat[i] = t.tv_sec * 1000;
	p->eat[i] += t.tv_usec / 1000;
}

void	ft_checkdeath(t_param *p)
{
	int	j;
	int	current;
	struct timeval	t;

	j = -1;
	while (++j < p->philosophers_nb)
	{
		gettimeofday(&t, NULL);
		current = t.tv_sec * 1000;
		current += t.tv_usec / 1000;
		if (current - p->eat[j] > (p->tt_die))
		{
			pthread_mutex_lock(&p->talk);
			printf("(%i) Philosopher %i died\n", ft_time(p), j + 1);
			p->dead = 1;
			break;
		}
	}
}

void	*ft_death(void	*v)
{
	t_param	*c;
	t_param	p;
	int	i;

	i = p.i;
	c = (t_param *)	v;
	p = *c;
		while(1)
	{
		if (c->dead == 1)
			break;
		ft_checkdeath(c);
	}
	return (NULL);
}
