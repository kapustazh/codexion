/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:24:40 by mnestere          #+#    #+#             */
/*   Updated: 2026/01/27 20:58:52 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	run(t_argvs *input)
{
	int coders_size;
	t_coder *coders;

	coders = malloc_coders(&coders_size, input);
	if (!coders)
		return ;
	create_thread(coders, &coders_size);
	join_treads(coders, &coders_size);
	free_mutex(coders, &coders_size);
	free(coders);
}