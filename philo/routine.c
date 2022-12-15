/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:14:17 by rchiewli          #+#    #+#             */
/*   Updated: 2022/12/15 21:21:07 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ptr)
{
	t_phi	*phil;

	phil = (t_phi *)ptr;
	if (phil->name % 2 == 0)
		usleep (1000);
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
			if (timenow - tdata->philo[i].lasteat > (size_t)tdata->av2)
			{
				tdata->died = 1;
				if (tdata->imm != tdata->av1)
					printf("%lu %d %s\n", timenow, tdata->philo[i].name, "died");
				return (NULL);
			}
			i++;
		}
		i = 0;
	}
	return (NULL);
}
