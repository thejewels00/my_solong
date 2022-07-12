/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:59:10 by jchennak          #+#    #+#             */
/*   Updated: 2021/11/29 18:16:25 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*cc;

	cc = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (cc[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
