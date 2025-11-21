/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuizu <msuizu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:17:38 by minpple           #+#    #+#             */
/*   Updated: 2025/11/22 00:21:38 by msuizu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*get_next_line(int fd)
{
	//static char	next[BUFFER_SIZE + 1];
	static char	*next;
	char		*line;
	char		*buffer;
	int			nb_read;
	int			i;

	i = 0;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (next)
	{
		line = ft_strdup(next);
		free(next);
	}
	else
		line = ft_calloc(1, sizeof(char));
	nb_read = 1;
	while ((ft_strchr(line, '\n') == NULL) && nb_read > 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		line = ft_strjoin(line, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
	}
	if (nb_read == 0)
	{
		free(buffer);
		if (*line)
			return (line);
		else
		{
			free(line);
			return (NULL);
		}
	}
	while (line[i] && line[i] != '\n')
		i++;
	next = ft_strdup(&line[i + 1]);
	line = ft_strndup(&line, i + 1);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*s;
	
	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}
