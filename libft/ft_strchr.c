/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:07:02 by jchennak          #+#    #+#             */
/*   Updated: 2021/11/29 18:01:55 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cc;

	i = 0;
	cc = (char *)s;
	while (cc[i] != '\0')
	{
		if (cc[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (cc[i] == c)
		return ((char *)&s[i]);
	return (0);
}
