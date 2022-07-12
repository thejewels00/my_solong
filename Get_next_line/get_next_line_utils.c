/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:50:06 by jchennak          #+#    #+#             */
/*   Updated: 2022/02/23 15:51:24 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cc;

	i = 0;
	cc = (char *)s;
	while (cc[i])
	{
		if (cc[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (cc[i] == c)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(ft_strlen(s1) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = (char)s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(len);
	if (!str)
		return (0);
	(void)ft_strlcpy(str, s1, len);
	(void)ft_strlcat(str, s2, len);
	return (str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;

	if (!s)
		return (NULL);
	if ((int)len > ft_strlen(s))
		len = ft_strlen(s);
	if ((int)start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
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
