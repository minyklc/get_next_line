/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpple <minpple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:50:21 by minpple           #+#    #+#             */
/*   Updated: 2025/11/20 13:39:37 by minpple          ###   ########.fr       */
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

char	*ft_newmalloc(char *before, int nb)
{
	char	*new;
	
	new = malloc(sizeof(char) * nb);
	nb--;
	while (nb >= 0)
	{
		new[nb] = before[nb];
		nb--;
	}
	free(before);
	return (new);
}
