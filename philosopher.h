/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:45:46 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/15 16:56:17 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

typedef struct s_param
{
	int	philosophers_nb;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	eat_nb;
} t_param;

int	ft_parsing(t_param *p, char **av, int ac);

#endif
