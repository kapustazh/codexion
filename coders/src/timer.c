/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:14:58 by mnestere          #+#    #+#             */
/*   Updated: 2026/02/08 01:51:33 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

long	get_elapsed_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return ((long long)time.tv_sec * 1000 + time.tv_usec / 1000);
}

long	get_current_time(t_argvs *input)
{
	return (get_elapsed_time() - input->start_time);
}
