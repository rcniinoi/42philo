/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:14:17 by rchiewli          #+#    #+#             */
/*   Updated: 2022/12/15 13:40:10 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



// int	ft_isdie(t_phi *phil, unsigned long timenow)
// {
// 	if (phil->common->isalive == 0)
// 		return (0);
// 	if ((timenow - phil->time_state) > phil->time_die)
// 	{
// 		phil->common->isalive = 0;
// 		phil->common->name = phil->name;
// 		phil->common->time = timenow;
// 		pthread_mutex_unlock(&phil->fork);
// 		pthread_mutex_unlock(&phil->next->fork);
// 		pthread_mutex_unlock(&phil->common->staticlock);
// 		pthread_mutex_unlock(&phil->common->printlock);
// 		return (0);
// 	}
// 	return (1);
// }

void	*routine(void *ptr)
{
	t_phi	*phil;

	phil = (t_phi *)ptr;
	if (phil->name % 2 == 0)
		usleep (phil->common->av3 * 1000);
	while (phil->common->died == 0)
	{
		ft_yipfork(phil);
		ft_dak(phil);
		ft_non(phil);
	}

	return (NULL);
}

void	*paralympic(void *ptr)
{
	t_stk	*tdata;
	int		i;
	size_t	timenow;

	i = 0;
	tdata = (t_stk *)ptr;
	while (tdata->died == 0)
	{
		while (i < tdata->av1)
		{
			timenow = ft_timenow(tdata);
			if (tdata->philo[i].immcount == tdata->av5)
			{
				pthread_mutex_lock(&tdata->staticlock);
				tdata->imm += 1;
				if (tdata->imm == tdata->av1)
					tdata->died = 1;
				pthread_mutex_unlock(&tdata->staticlock);
			}
			if (timenow - tdata->philo[i].lasteat >= (size_t)tdata->av2)
			{
				printf("now %lu last eat %lu av2 %lu\n", timenow, tdata->philo[i].lasteat, (size_t)tdata->av2);
				tdata->died = 1;
				if (tdata->imm != tdata->av1)
				{
					printf("%lu %d %s\n", timenow, tdata->philo[i].name, "died");
				}
				return (NULL);
			}
			i++;
		}
		i = 0;
	}
	return (NULL);
}
