/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpple <minpple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:17:38 by minpple           #+#    #+#             */
/*   Updated: 2025/11/20 13:37:50 by minpple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		nb_read;
    char	c;
	int		i;

	nb_read = -1;
	i = 0;
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	nb_read = read(fd, &c, 1);
	if (nb_read == -1)
	{
		free(line);
		return (line = NULL);
	}
	while (nb_read != 0 && i < BUFFER_SIZE && c != '\0' && c != '\n')
	{
		line[i] = c;
		nb_read = read(fd, &c, 1);
		line = ft_newmalloc(line, i + 1);
		i++;
	}
	while (nb_read != 0 && c != '\n' && c != '\0')
		nb_read = read(fd, &c, 1);
	if (c == '\n' || c == '\0')
		line[i] = c;
	return (line);
}

int main(void)
{
	int	i;
	char *test;

	i = 0;
    int fd = open("test.txt", O_RDONLY);
	while (i < 9)
	{
    	test = get_next_line(fd);
    	ft_putstr(test);
    	free(test);
		i++;
	}
    close(fd);
}
