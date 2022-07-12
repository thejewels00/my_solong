/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchennak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:37:27 by jchennak          #+#    #+#             */
/*   Updated: 2021/11/28 14:42:20 by jchennak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static char	**ft_freeall(char **tab, int i)
{
	int	a;

	a = 0;
	while (a <= i)
	{
		free(tab[a]);
		a++;
	}
	free(tab);
	return (NULL);
}

static int	ft_nbrmot(char const *s, char a)
{
	int	i;
	int	nbrmot;

	i = 0;
	nbrmot = 0;
	while (s[i])
	{
		if (s[i] != a)
		{
			nbrmot++;
			while (s[i] && s[i] != a)
				i++;
		}
		else
			i++;
	}
	return (nbrmot);
}

static char	**ft_allocationlpl(char **t, char const *s, char a, int n)
{
	int	l;
	int	len;
	int	c;

	l = 0;
	c = 0;
	while (l < n && s[c])
	{
		len = 0;
		while (s[c] && s[c] != a)
		{
			len++;
			c++;
		}
		if (len != 0)
		{
			t[l] = (char *)malloc(sizeof(char) * (len + 1));
			if (!t[l])
				return (ft_freeall(t, l));
			l++;
		}
		c++;
	}
	t[n] = 0;
	return (t);
}

static void	ft_remplissage(char **t, char const *s, char a, int n)
{
	int	l;
	int	c;
	int	cc;

	l = 0;
	c = 0;
	while (l < n && s[c])
	{
		cc = 0;
		if (s[c] != a)
		{
			while (s[c] && s[c] != a)
			{
				t[l][cc] = s[c];
				cc++;
				c++;
			}
			t[l][cc] = '\0';
			l++;
		}
		else
			c++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**t;

	if (s == NULL)
		return (0);
	n = ft_nbrmot(s, c);
	t = (char **)malloc(sizeof(char *) * (n + 1));
	if (!t)
		return (0);
	t = ft_allocationlpl(t, s, c, n);
	if (!t)
		return (0);
	ft_remplissage(t, s, c, n);
	return (t);
}
