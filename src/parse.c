/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnestere <mnestere@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:04:57 by mnestere          #+#    #+#             */
/*   Updated: 2026/01/24 21:47:59 by mnestere         ###   ########.fr       */
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

bool	validate_argvs(char const *argv[])
{
	int	i;

	i = 1;
	while (*argv[i] && i < 8)
	{
		if (ft_strtol(argv[i]) >= INT_MAX || ft_strtol(argv[i]) <= 0)
			return (false);
		i++;
	}
	if (strcmp(argv[8], "fifo") == 0 || strcmp(argv[8], "edf") == 0)
		return (true);
	else
		return (false);
}

t_argvs	init_argvs(char const **argv)
{
	t_argvs	argvs;

	argvs.number_of_coders = atoi(argv[1]);
	argvs.time_to_burnout = atoi(argv[2]);
	argvs.time_to_compile = atoi(argv[3]);
	argvs.time_to_debug = atoi(argv[4]);
	argvs.time_to_refactor = atoi(argv[5]);
	argvs.number_of_compiles_required = atoi(argv[6]);
	argvs.dongle_cooldown = atoi(argv[7]);
	argvs.scheduler = argv[8];
	return (argvs);
}
