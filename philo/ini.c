/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:12:04 by rchiewli          #+#    #+#             */
/*   Updated: 2022/12/15 21:19:31 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philoini(t_stk *tdata)
{
	int	i;

	i = 0;
	while (i < tdata->av1)
	{
		tdata->philo[i].name = i + 1;
		pthread_mutex_init(&tdata->philo[i].fork, NULL);
		tdata->philo[i].common = tdata;
		tdata->philo[i].immcount = 0;
		tdata->philo[i].lasteat = ft_timenow(tdata);
		if (i == (tdata->av1 - 1))
			tdata->philo[i].next = &tdata->philo[0];
		else
			tdata->philo[i].next = &tdata->philo[i + 1];
		i++;
	}
}

void	ft_dataini(char **argv, t_stk *tdata, size_t stime)
{
	tdata->av1 = ft_atoi(argv[1]);
	tdata->av2 = ft_atoi(argv[2]);
	tdata->av3 = ft_atoi(argv[3]);
	tdata->av4 = ft_atoi(argv[4]);
	if (argv[5])
		tdata->av5 = ft_atoi(argv[5]);
	else
		tdata->av5 = -1;
	tdata->timestart = stime;
	tdata->died = 0;
	tdata->imm = 0;
	tdata->philo = malloc(sizeof(t_phi) * tdata->av1);
	pthread_mutex_init(&tdata->printlock, NULL);
	pthread_mutex_init(&tdata->staticlock, NULL);
}

void	ft_startini(char **argv, t_stk *tdata)
{
	size_t			time_in_millis;
	struct timeval	ts;

	gettimeofday(&ts, NULL);
	time_in_millis = ts.tv_sec * 1000 + ts.tv_usec / 1000;
	ft_dataini(argv, tdata, time_in_millis);
	ft_philoini(tdata);
}
