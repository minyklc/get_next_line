/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minpple <minpple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:50:21 by minpple           #+#    #+#             */
/*   Updated: 2025/11/21 22:05:59 by minpple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		j;
	int		len;

	i = -1;
	j = -1;
	if (s1 == NULL)
		string = ft_calloc(BUFFER_SIZE, sizeof(char));
	else
	{
		len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		string = ft_calloc(len + 1, sizeof(char));
	}
	if (string == NULL)
		return (NULL);
	while (s1 != NULL && s1[++i])
		string[++j] = s1[i];
	i = -1;
	while (s2 != NULL && s2[++i])
		string[++j] = s2[i];
	string[++j] = '\0';
	return (string);
}

char	*ft_strdup(const char *src)
{
	char	*str;
	int		size;
	int		i;

	size = ft_strlen((char *)src);
	i = 0;
	str = ft_calloc(size + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(const char *s)
{
	int	index;

	index = -1;
	while (*(s + (++index)))
		;
	return (index);
}

char	*ft_strchr(const char *s, int c)
{
	char	caracter;
	int		i;

	caracter = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == caracter)
			return (((char *)s) + i);
		i++;
	}
	if (caracter == '\0')
		return (((char *)s) + i);
	return (NULL);
}