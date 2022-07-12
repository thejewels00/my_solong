/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:04:14 by jchennak          #+#    #+#             */
/*   Updated: 2021/11/29 23:08:06 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	k;
	size_t	i;

	k = ft_strlen(src);
	if (!dstsize)
		return (ft_strlen(src));
	j = ft_strlen(dst);
	i = 0;
	if (j > dstsize)
		return (k + dstsize);
	while (j + i < dstsize - 1 && src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (j + k);
}
