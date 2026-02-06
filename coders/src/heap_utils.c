/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:11:59 by mnestere          #+#    #+#             */
/*   Updated: 2026/02/06 22:15:25 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

void	swap_nodes(t_node *a, t_node *b)
{
	t_node	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
