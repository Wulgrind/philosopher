/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:52:15 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/15 17:08:48 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] > '9' || av[i][j] < '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parsing(t_param *p, char **av, int ac)
{
	if (!ft_isdigit(av))
		return (0);
	p->philosophers_nb = ft_atoi(av[1]);
	p->tt_die = ft_atoi(av[2]);
	p->tt_eat = ft_atoi(av[3]);
	p->tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		p->eat_nb = ft_atoi(av[5]);
	return (1);
}
