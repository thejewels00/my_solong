/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:25:57 by jchennak          #+#    #+#             */
/*   Updated: 2021/11/29 18:14:51 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s) || len == 0)
		return (ft_calloc(1, 1));
	p = malloc(len + 1);
	if (!p)
		return (0);
	i = 0;
	while (i < len && s[start])
	{
		p[i] = (char)s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
