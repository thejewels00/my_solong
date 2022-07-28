/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelandal <aelandal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:10:33 by jchennak          #+#    #+#             */
/*   Updated: 2022/07/27 12:44:44 by aelandal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	ft_bufflen(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*ft_stock_return(int r_read, char **save)
{
	int		len;
	char	*tmp;
	char	*tmp_1;

	if (r_read < 0 || !(*save))
		return (NULL);
	len = ft_bufflen(*save);
	tmp = ft_substr(*save, 0, len + 1);
	tmp_1 = ft_substr(*save, len + 1, ft_strlen(*save) - len);
	free(*save);
	if (ft_strlen(tmp_1) == 0)
	{
		*save = NULL;
		free (tmp_1);
		tmp_1 = NULL;
	}
	else
		*save = tmp_1;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*buff;
	int			r_read;
	char		*line;

	if (fd < 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	r_read = read(fd, buff, BUFFER_SIZE);
	while (r_read > 0)
	{
		buff[r_read] = '\0';
		if (!save)
			save = ft_strdup("");
		line = ft_strjoin(save, buff);
		free(save);
		save = line;
		if (ft_strchr(save, '\n') != NULL)
			break ;
		r_read = read(fd, buff, BUFFER_SIZE);
	}
	free (buff);
	return (ft_stock_return(r_read, &save));
}
