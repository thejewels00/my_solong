/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:11:14 by jchennak          #+#    #+#             */
/*   Updated: 2021/11/13 17:17:13 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = len;
	if (dst > src)
		while (i-- > 0)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
