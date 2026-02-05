/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 20:20:00 by mnestere          #+#    #+#             */
/*   Updated: 2026/02/05 20:20:01 by mnestere         ###   ########.fr       */
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
