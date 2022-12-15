/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:15:14 by rchiewli          #+#    #+#             */
/*   Updated: 2022/12/15 12:25:38 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_timenow(t_stk *tdata)
{
	struct timeval	tv;
	size_t	time_in_milli;

	gettimeofday(&tv, NULL);
	time_in_milli = tv.tv_sec * 1000LL + tv.tv_usec / 1000;
	return (time_in_milli - tdata->timestart);
}

void	ft_printphil(t_phi *philo, char *str, size_t time)
{
	pthread_mutex_lock(&philo->common->printlock);
	if (philo->common->died == 0 && philo->common->imm < philo->common->av1)
	{
		printf("%lu %d %s\n", time, philo->name, str);
	}
	pthread_mutex_unlock(&philo->common->printlock);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	rst;
	int	sign;

	sign = 1;
	rst = 0;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		rst *= 10;
		rst += (str[i] - '0');
		i++;
	}
	return (rst * sign);
}

void	ft_mislip(int vela)
{
	int i;

	i = 0;
	while(i < vela)
	{
		usleep(vela);
		i += vela;
	}
}