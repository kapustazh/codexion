/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:04:57 by mnestere          #+#    #+#             */
/*   Updated: 2026/01/27 16:27:31 by mnestere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/codexion.h"

long	ft_strtol(const char *str)
{
	long	result;
	long	sign;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	validate_argvs(int argc, char const *argv[])
{
	int	i;

	if (argc != 9)
	{
		printf("Error: Invalid number of arguments");
		return (0);
	}
	i = 1;
	while (*argv[i] && i < 8)
	{
		if (ft_strtol(argv[i]) >= INT_MAX || ft_strtol(argv[i]) <= 0)
		{
			printf("Invalid arguments, try again!");
			return (0);
		}
		i++;
	}
	if (strcmp(argv[8], "fifo") == 0 || strcmp(argv[8], "edf") == 0)
		return (1);
	else
	{
		printf("Invalid arguments, try again!");
		return (0);
	}
}

t_argvs	*init_argvs(t_argvs *input, char const **argv)
{
	input->number_of_coders = atoi(argv[1]);
	input->time_to_burnout = atoi(argv[2]);
	input->time_to_compile = atoi(argv[3]);
	input->time_to_debug = atoi(argv[4]);
	input->time_to_refactor = atoi(argv[5]);
	input->number_of_compiles_required = atoi(argv[6]);
	input->dongle_cooldown = atoi(argv[7]);
	input->scheduler = argv[8];
	return (input);
}
