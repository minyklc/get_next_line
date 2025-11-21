/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuizu <msuizu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 04:12:16 by minpple           #+#    #+#             */
/*   Updated: 2025/11/22 00:15:29 by msuizu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H_
# define GNL_H_

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_bzero(void *tab, size_t n);
void    *ft_calloc(size_t nmemb, size_t size);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *src);
char	*ft_strndup(char **src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif