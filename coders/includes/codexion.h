/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mnestere <mnestere@student.42heilbronn.de> +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/01/24 15:28:06 by mnestere          #+#    #+#             */
/*   Updated: 2026/01/24 21:48:11 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_argvs
{
	int				number_of_coders;
	int				time_to_burnout;
	int				time_to_compile;
	int				time_to_debug;
	int				time_to_refactor;
	int				number_of_compiles_required;
	int				dongle_cooldown;
	long			start_time;
	char const		*scheduler;
	pthread_mutex_t	print_mutex;
}					t_argvs;

typedef struct s_coder
{
	int				id;
	pthread_t		thread;
	t_argvs			*input;
	pthread_mutex_t	left_dongle;
	pthread_mutex_t	*right_dongle;
}					t_coder;

void				run(t_argvs *input);
long				ft_strtol(const char *str);
int					validate_argvs(int argc, char const *argv[]);
t_argvs				*init_argvs(t_argvs *input, char const *argv[]);
void				init_threads(t_coder *coders, int *number_of_coders);
void				*do_routine(void *arg);
t_coder				*malloc_coders(int *coders_size, t_argvs *input);
long				get_elapsed_time(void);
long				get_current_time(t_argvs *input);

#endif // CODEXION_H