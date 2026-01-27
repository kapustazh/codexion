/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: mnestere <mnestere@student.42heilbronn.de> +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/01/24 15:18:43 by mnestere          #+#    #+#             */
/*   Updated: 2026/01/24 21:48:53 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

int	main(int argc, char const *argv[])
{
	t_argvs	args;

	if (!validate_argvs(argc, argv))
		return (1);
	init_argvs(&args, argv);
	printf("%d", args.dongle_cooldown);
	return (0);
}
