/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:45:46 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/21 12:46:59 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

typedef struct s_param
{
	int	philosophers_nb;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	eat_nb;
	int	end;
	pthread_t	*thread_id;
	pthread_mutex_t *fork;
	int	phil_max;
	int	i;
} t_param;

int	ft_parsing(t_param *p, char **av, int ac);
int	ft_createphilo(t_param *p);
void	*ft_newphilo(void *v);
int	ft_forks(t_param *p);
int	ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_itoa(int nb);

#endif
