/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmidik <tibetmdk@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:04:15 by tmidik            #+#    #+#             */
/*   Updated: 2025/02/21 21:15:00 by tmidik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *remain)
{
	char		*buffer;
	int			readed;

	readed = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(remain, '\n') && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			free(remain);
			return (NULL);
		}
		buffer[readed] = '\0';
		remain = ft_strjoin(remain, buffer);
	}
	free(buffer);
	return (remain);
}

static char	*line_generator(char *str)
{
	int		i;
	char	*line;

	if (!str || str[0] == '\0')
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = ft_substr(str, 0, i + 1);
	return (line);
}

static char	*update_line(char *str)
{
	int		i;
	char	*new_remain;

	if (!str || str[0] == '\0')
		return (free(str), NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new_remain = ft_substr(str, i + 1, ft_get_strlen(str) - i - 1);
	free(str);
	return (new_remain);
}

char	*get_next_line(int fd)
{
	static char	*remain = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remain = read_line(fd, remain);
	if (!remain)
		return (NULL);
	line = line_generator(remain);
	remain = update_line(remain);
	return (line);
}
