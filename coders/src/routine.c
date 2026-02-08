/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:55:58 by mnestere          #+#    #+#             */
/*   Updated: 2026/02/08 03:07:59 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

static void	print_message(char *msg, t_coder *coder)
{
	printf("%ld %i %s\n", get_current_time(coder->input), coder->id, msg);
}

void	*do_routine(void *arg)
{
	t_coder	*this_coder;

	this_coder = (t_coder *)arg;
	return (NULL);
}
