/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:29:38 by mnestere          #+#    #+#             */
/*   Updated: 2026/01/30 15:02:04 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

t_coder	*malloc_coders(int *coders_size, t_argvs *input)
{
	t_coder	*coders;
	int		i;

	i = 0;
	*coders_size = input->number_of_coders;
	coders = malloc(sizeof(t_coder) * *coders_size);
	if (!coders)
		return (NULL);
	i = 0;
	while (i < *coders_size)
	{
		coders[i].input = input;
		i++;
	}
	return (coders);
}
void	create_thread(t_coder *coders, int *number_of_coders)
{
	int	i;

	i = 0;
	while (i < *number_of_coders)
	{
		coders[i].id = i + 1;
		pthread_mutex_init(&coders[i].lock, NULL);
		pthread_create(&coders[i].thread, NULL, &do_routine, &coders[i]);
		i++;
	}
}

void	join_treads(t_coder *coders, int *number_of_coders)
{
	int	i;

	i = 0;
	while (i < *number_of_coders)
	{
		pthread_join(coders[i].thread, NULL);
		i++;
	}
}

void	free_mutex(t_coder *coders, int *number_of_coders)
{
	int	i;

	i = 0;
	while (i < *number_of_coders)
	{
		pthread_mutex_destroy(&coders[i].lock);
		i++;
	}
}
