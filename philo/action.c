/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:11:34 by rchiewli          #+#    #+#             */
/*   Updated: 2022/12/15 21:19:16 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(t_phi *phil, size_t time)
{
	size_t	now;

	now = ft_gettime();
	while (ft_gettime() - now < time)
	{
		if (phil->common->died)
			break ;
		usleep(200);
	}
}

int	ft_yipfork(t_phi *phil)
{
	size_t	timenow;

	pthread_mutex_lock(&phil->fork);
	timenow = ft_timenow(phil->common);
	ft_printphil(phil, "has taken a fork", timenow);
	pthread_mutex_lock(&phil->next->fork);
	timenow = ft_timenow(phil->common);
	ft_printphil(phil, "has taken a fork", timenow);
	return (1);
}

int	ft_dak(t_phi *phil)
{
	size_t	timenow;

	timenow = ft_timenow(phil->common);
	ft_printphil(phil, "is eating", timenow);
	phil->lasteat = timenow;
	if (phil->common->av5 != -1)
		phil->immcount += 1;
	if (phil->immcount == phil->common->av5)
	{
		pthread_mutex_lock(&phil->common->staticlock);
		phil->common->imm += 1;
		if (phil->common->imm == phil->common->av1)
			phil->common->died = 1;
		pthread_mutex_unlock(&phil->common->staticlock);
	}
	my_usleep(phil, phil->common->av3);
	pthread_mutex_unlock(&phil->fork);
	pthread_mutex_unlock(&phil->next->fork);
	return (1);
}

int	ft_non(t_phi *phil)
{
	size_t	timenow;

	timenow = ft_timenow(phil->common);
	ft_printphil(phil, "is sleeping", timenow);
	my_usleep(phil, phil->common->av4);
	timenow = ft_timenow(phil->common);
	ft_printphil(phil, "is thinking", timenow);
	return (1);
}
