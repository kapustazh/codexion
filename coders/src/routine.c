/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:55:58 by mnestere          #+#    #+#             */
/*   Updated: 2026/01/27 20:26:00 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	*do_routine(void *arg)
{
	t_coder	*this_coder;

	this_coder = (t_coder *)arg;
	pthread_mutex_lock(&this_coder->input->print_mutex);
	pthread_mutex_lock(this_coder->right_dongle);
	printf("%d has taken a dongle\n", this_coder->id);
	printf("%d is compiling\n", this_coder->id);
	printf("%d is debugging\n", this_coder->id);
	printf("%d is refactoring\n", this_coder->id);
	printf("%d burned out\n", this_coder->id);
	pthread_mutex_unlock(this_coder->right_dongle);
	pthread_mutex_unlock(&this_coder->input->print_mutex);
	return (NULL);
}
