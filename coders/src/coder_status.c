/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42heilbronn.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 03:06:09 by mnestere          #+#    #+#             */
/*   Updated: 2026/02/08 03:11:52 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/coders.h"


void take_dongles(t_coder *coder)
{
	pthread_mutex_lock(&coder->left_dongle.dongle);
	pthread_mutex_lock(&coder->right_dongle->dongle);
}

void release_dongles(t_coder *coder)
{
	pthread_mutex_unlock(&this_coder->left_dongle.dongle);
	pthread_mutex_unlock(&this_coder->right_dongle->dongle);
}

void update_last_compiled_t(t_coder *coder)
{
	pthread_mutex_lock(&coder->last_compiled_t);
	coder->last_compiled_t = get_elapsed_time(coder->input);
	pthread_mutex_unlock(&coder->last_compiled_t);
}

void update_times_compile(t_coder *coder)
{
	pthread_mutex_lock(&coder->times_compiled_mutex.dongle);
	coder->times_compiled++;
	pthread_mutex_unlock(&coder->times_compiled_mutex.dongle);
}