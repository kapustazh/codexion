/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:29:38 by mnestere          #+#    #+#             */
/*   Updated: 2026/02/08 01:53:14 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

static void	init_mutex(t_coder *coders, int *number_of_coders)
{
	int	i;

	i = 0;
	while (i < *number_of_coders)
	{
		coders[i].id = i + 1;
		pthread_mutex_init(&coders[i].left_dongle, NULL);
		i++;
	}
	i = 0;
	while (i < *number_of_coders)
	{
		if (i == 0)
			coders[i].right_dongle = &coders[*number_of_coders - 1].left_dongle;
		else
			coders[i].right_dongle = &coders[i - 1].left_dongle;
		i++;
	}
}

static void	create_threads(t_coder *coders, int *number_of_coders)
{
	int	i;

	i = 0;
	while (i < *number_of_coders)
	{
		if (pthread_create(&coders[i].thread, NULL, do_routine, &coders[i]))
			exit(1);
		i++;
	}
}

static void	join_treads(t_coder *coders, int *number_of_coders)
{
	int	i;

	i = 0;
	while (i < *number_of_coders)
	{
		if (pthread_join(coders[i].thread, NULL))
			exit(1);
		i++;
	}
}

static void	free_mutex(t_coder *coders, int *number_of_coders)
{
	int	i;

	i = 0;
	while (i < *number_of_coders)
	{
		pthread_mutex_destroy(&coders[i].left_dongle);
		i++;
	}
}

void	init_threads(t_coder *coders, int *number_of_coders)
{
	init_mutex(coders, number_of_coders);
	create_threads(coders, number_of_coders);
	join_treads(coders, number_of_coders);
	free_mutex(coders, number_of_coders);
}
