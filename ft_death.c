/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:25:29 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/23 14:35:35 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_eat(t_param *p, int i)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	p->eat[i] = t.tv_sec * 1000;
	p->eat[i] += t.tv_usec / 1000;
	p->eat2[i] += 1;
}

void	ft_checkdeath2(t_param *p)
{
	int	j;

	if (p->ac == 6)
	{
		while (1)
		{
			j = -1;
			while (++j < p->philosophers_nb)
			{
				if (p->eat2[j] != p->eat_nb + 1)
					break ;
			}
			if (j == p->philosophers_nb)
				break;
		}
		pthread_mutex_lock(&p->talk);
		p->dead = 1;
	}
}

void	ft_checkdeath(t_param *p)
{
	int				j;
	int				current;
	struct timeval	t;

	j = -1;
	while (++j < p->philosophers_nb)
	{
		gettimeofday(&t, NULL);
		current = t.tv_sec * 1000;
		current += t.tv_usec / 1000;
		if ((current - p->eat[j]) > (p->tt_die))
		{
			pthread_mutex_lock(&p->talk);
			printf("(%i) Philosopher %i died\n", ft_time(p), j + 1);
			p->dead = 1;
			if (p->dead == 1)
				break ;
		}
	}
	ft_checkdeath2(p);
}

void	*ft_death(void	*v)
{
	t_param	*c;
	t_param	p;
	int		i;

	i = p.i;
	c = (t_param *) v;
	p = *c;
	c->dead = 0;
	while (1)
	{
		usleep(100);
		if (c->dead == 1)
			break ;
		ft_checkdeath(c);
	}
	printf("test");
	return (NULL);
}
