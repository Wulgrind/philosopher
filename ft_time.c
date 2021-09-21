/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:34:48 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/21 17:09:24 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_timestart(t_param *p)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	p->start = t.tv_sec / 1000;
	p->start += t.tv_usec * 1000;
}

int	ft_time(t_param *p)
{
	int	i;
	struct timeval	t;

	gettimeofday(&t, NULL);
	i = t.tv_sec / 1000;
	i += t.tv_usec * 1000;	
	i -= p->start;
	return (i);
}
