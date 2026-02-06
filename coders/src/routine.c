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

#define DONGLE "has taken a dongle"
#define COMPILE "compiling"
#define DEBUG "debugging"
#define REFACTOR "refactoring"
#define BURNOUT "burned out"

static void	print_message(char *msg, t_coder *coder)
{
	printf("%ld %i %s\n", get_current_time(coder->input), coder->id, msg);
}

void	*do_routine(void *arg)
{
	t_coder	*this_coder;

	this_coder = (t_coder *)arg;
	pthread_mutex_lock(&this_coder->input->print_mutex);
	pthread_mutex_lock(this_coder->right_dongle);
	print_message(DONGLE, this_coder);
	print_message(COMPILE, this_coder);
	print_message(DEBUG, this_coder);
	print_message(REFACTOR, this_coder);
	print_message(BURNOUT, this_coder);
	pthread_mutex_unlock(this_coder->right_dongle);
	pthread_mutex_unlock(&this_coder->input->print_mutex);
	return (NULL);
}
