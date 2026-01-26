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
	t_argvs args;

	if (argc != 9)
	{
		printf("Error: Invalid number of arguments");
		return (0);
	}
	if (!validate_argvs(argv))
	{
		printf("Invalid arguments, try again!");
		return (0);
	}
	args = init_argvs(argv);
	printf("%d", args.dongle_cooldown);
	return (0);
}
