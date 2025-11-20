/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpple <minpple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 04:12:16 by minpple           #+#    #+#             */
/*   Updated: 2025/11/19 15:34:04 by minpple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H_
# define GNL_H_

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	ft_putstr(char *s);
char	*ft_newmalloc(char *before, int nb);

#endif