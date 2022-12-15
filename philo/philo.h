/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:17:26 by rchiewli          #+#    #+#             */
/*   Updated: 2022/12/15 14:26:24 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>
# include <time.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phi
{
	int				name;
	int				immcount;
	pthread_mutex_t	fork;
	pthread_t		phit;
	unsigned long	time_now;
	unsigned long	lasteat;
	struct s_stk	*common;
	struct s_phi	*next;
}	t_phi;

typedef struct s_stk
{
	int				av1;
	int				av2;
	int				av3;
	int				av4;
	int				av5;
	int				imm;
	unsigned long	timestart;
	pthread_t		omaewamoshideru;
	int				died;
	pthread_mutex_t	printlock;
	pthread_mutex_t	staticlock;
	struct s_phi	*philo;
}	t_stk;

int			ft_atoi(const char *str);
void		ft_dataini(char **argv, t_stk *tdata, size_t stime);
void		ft_startini(char **argv, t_stk *tdata);
void		ft_philoini(t_stk *tdata);
size_t		ft_timenow(t_stk *tdata);
void		ft_printphil(t_phi *philo, char *str, size_t time);
void		*routine(void *ptr);
void		ft_start(t_stk *tdata);
int			ft_yipfork(t_phi *phil);
int			ft_dak(t_phi *phil);
int			ft_non(t_phi *phil);
void		*paralympic(void *ptr);
void		*routine2(void *ptr);
void		ft_freephi(t_stk *tdata);
void		ft_mislip(useconds_t vela);
size_t		ft_gettime(void);
// int				ft_isdie(t_phi *phil, unsigned long timenow);
// void			*kwai(void *ptr);

#endif
