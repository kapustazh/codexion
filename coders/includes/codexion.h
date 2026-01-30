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
	char const		*scheduler;
}					t_argvs;

typedef struct s_coder
{
	int				id;
	pthread_t		thread;
	t_argvs			*input;
	pthread_mutex_t	lock;
}					t_coder;

void				run(t_argvs *input);
long				ft_strtol(const char *str);
int					validate_argvs(int argc, char const *argv[]);
t_argvs				*init_argvs(t_argvs *input, char const *argv[]);
void				create_thread(t_coder *coders, int *number_of_coders);
void				*do_routine(void *arg);
void				join_treads(t_coder *coders, int *number_of_coders);
void				free_mutex(t_coder *coders, int *number_of_coders);
t_coder				*malloc_coders(int *coders_size, t_argvs *input);
#endif // CODEXION_H