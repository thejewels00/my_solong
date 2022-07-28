/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <jchennak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:32:36 by jchennak          #+#    #+#             */
/*   Updated: 2022/07/28 11:32:36 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	all;

	if (argc != 2)
	{
		write(1, "USAGE : ./so_long  Map.ber\n", 28);
		return (0);
	}
	error_management(argv[1], &all);
	window_design(&all);
	return (0);
}
