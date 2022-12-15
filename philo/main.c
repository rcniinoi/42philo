/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:03:15 by rchiewli          #+#    #+#             */
/*   Updated: 2022/12/14 22:40:52 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_hardcode(t_stk *tdata)
{
	pthread_create(&tdata->philo->phit, NULL, routine2, tdata->philo);
	pthread_create(&tdata->omaewamoshideru, NULL, paralympic, tdata);
	pthread_join(tdata->philo->phit, NULL);
	pthread_join(tdata->omaewamoshideru, NULL);
}

void	*routine2(void *ptr)
{
	t_phi	*phil;
	size_t	timenow;

	phil = (t_phi *)ptr;
	timenow = ft_timenow(phil->common);
	pthread_mutex_lock(&phil->fork);
	ft_printphil(phil, "has taken a fork", timenow);
	usleep(phil->common->av2 * 1000);
	return (NULL);
}

void	ft_start(t_stk *tdata)
{
	int	i;

	i = 0;
	while (i < tdata->av1)
	{
		if (pthread_create(&tdata->philo[i].phit, NULL, routine, \
			&tdata->philo[i]) == -1)
			printf ("pth create %d failed\n", i);
		i++;
		// usleep(100);
	}
	if (pthread_create(&tdata->omaewamoshideru, NULL, paralympic, tdata) == -1)
		printf ("pth create kuy failed\n");
	i = 0;
	while (i < tdata->av1)
	{
		if (pthread_join(tdata->philo[i].phit, NULL) != 0)
			perror("join");
		// if (pthread_detach(tdata->philo[i].phit) != 0)
		// 	perror("detach");
		i++;
	}
	if (pthread_join(tdata->omaewamoshideru, NULL) != 0)
		printf ("join %d errored\n", i);
}

int	main(int argc, char **argv)
{
	t_stk	*tdata;

	if (argc < 5)
		return (printf("Mung nub pen mai\n"), 0);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 1)
			return (0);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 60 || \
		ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
		{
			printf("pongtai kuy\n");
			return (0);
		}
	tdata = malloc(sizeof(t_stk));
	ft_startini(argv, tdata);
	// printf("-%d-\n", tdata->av1);
	if (tdata->av1 > 1)
		ft_start(tdata);
	else if (tdata->av1 == 0)
		printf("pongtai kuy\n");
	else if (tdata->av1 == 1)
		ft_hardcode(tdata);
	// ft_freephi(tdata);
	free(tdata->philo);
	free(tdata);
}
