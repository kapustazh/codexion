/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:07:34 by mnestere          #+#    #+#             */
/*   Updated: 2026/02/08 03:17:48 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// struct timeval {
//     time_t      tv_sec;
//     suseconds_t tv_usec;
// };

typedef enum e_coder_status
{
	COMPILING,
	DEBUGGING,
	REFACTORING,
	BURNED_OUT,
	ENOUGH
} t_coder_status;

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
//	pthread_t		monitor_thread;
}					t_argvs;

typedef struct s_coder
{
	int				id;
	int				earliest_deadline;
	pthread_t		thread;
	t_argvs			*input;
	s_dongle		left_dongle;
	s_dongle		*right_dongle;
	int				times_compiled;
	long long		last_compiled_time;
	pthread_mutex_t	last_compiled_time_mutex;
	pthread_mutex_t times_compiled_mutex;
}					t_coder;

typedef struct s_dongle
{
	pthread_mutex_t		dongle;
	t_argvs				*input;
}					t_dongle;

// heap
typedef struct s_node
{
	int				coder_id;
	long long		priority_value;
}					t_node;

typedef struct s_heap
{
	t_node			*array;
	int				size;
	int				capacity;
}					t_heap;

void				run(t_argvs *input);
long				ft_strtol(const char *str);
int					validate_argvs(int argc, char const *argv[]);
t_argvs				*init_argvs(t_argvs *input, char const *argv[]);
void				init_threads(t_coder *coders, int *number_of_coders);
void				*do_routine(void *arg);
t_coder				*malloc_coders(int *coders_size, t_argvs *input);
long				get_elapsed_time(void);
long				get_current_time(t_argvs *input);
void				swap_nodes(t_node *a, t_node *b);

// heap funcs
t_heap				*init_heap(int max_size);
int					heap_peek(t_heap *heap);
void				heap_push(t_heap *heap, int id, long long prio);
int					heap_pop(t_heap *heap);

#endif // CODEXION_H