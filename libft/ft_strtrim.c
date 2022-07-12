/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:42:23 by jchennak          #+#    #+#             */
/*   Updated: 2021/11/28 23:35:42 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_exist(char const *set, char a)
{
	while (*set)
	{
		if (*set == a)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (!set || !s1)
		return (0);
	i = 0;
	len = ft_strlen(s1);
	while (i < len && ft_exist(set, s1[i]))
		i++;
	if (i == len)
		return (ft_strdup(""));
	len--;
	while (ft_exist(set, s1[len]))
		len--;
	res = ft_substr(s1, i, len - i + 1);
	return (res);
}
