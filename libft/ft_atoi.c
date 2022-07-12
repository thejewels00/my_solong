/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:18:31 by jchennak          #+#    #+#             */
/*   Updated: 2021/11/29 22:08:21 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	nbr;
	int				sign;

	sign = 1;
	i = 0;
	nbr = 0;
	while (str[i] == ' ' || (str[i] >= '\b' && str[i] <= '\r'))
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
			nbr = nbr * 10 + str[i++] - '0';
	if (sign == 1 && nbr >= 9223372036854775807)
		return (-1);
	if (sign == -1 && nbr > 9223372036854775807)
		return (0);
	return (sign * nbr);
}
