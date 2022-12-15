/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:11:34 by rchiewli          #+#    #+#             */
/*   Updated: 2022/12/15 13:38:11 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_yipfork(t_phi *phil)
{
	size_t	timenow;

	// if (phil->common->died == 1)
	// 	return (0);
	// pthread_mutex_lock(&phil->common->staticlock);
	pthread_mutex_lock(&phil->fork);
	timenow = ft_timenow(phil->common);
	ft_printphil(phil, "has taken a fork", timenow);
	pthread_mutex_lock(&phil->next->fork);
	timenow = ft_timenow(phil->common);
	ft_printphil(phil, "has taken a fork", timenow);
	// pthread_mutex_unlock(&phil->common->staticlock);
	return(1);
}

int	ft_dak(t_phi *phil)
{
	size_t	timenow;

	// if (phil->common->died == 1)
	// 	return (0);
	timenow = ft_timenow(phil->common);
	ft_printphil(phil, "is eating", timenow);
	phil->lasteat = timenow;
	if (phil->common->av5 != -1)
		phil->immcount += 1;
	// if (phil->immcount == phil->common->av5)
	// {
	// 	pthread_mutex_lock(&phil->common->staticlock);
	// 	phil->common->imm += 1;
	// 	if (phil->common->imm == phil->common->av1)
	// 		phil->common->died = 1;
	// 	pthread_mutex_unlock(&phil->common->staticlock);
	// }
	usleep(phil->common->av3 * 1000);
	pthread_mutex_unlock(&phil->fork);
	pthread_mutex_unlock(&phil->next->fork);
	// printf("imm %d\n", phil->common->imm);
	return (1);
}

int	ft_non(t_phi *phil)
{
	size_t	timenow;

	// if (phil->common->died == 1)
	// 	return (0);
	timenow = ft_timenow(phil->common);
	ft_printphil(phil, "is sleeping", timenow);
	usleep(phil->common->av4 * 1000);
	timenow = ft_timenow(phil->common);
	ft_printphil(phil, "is thinking", timenow);
	return (1);
}
