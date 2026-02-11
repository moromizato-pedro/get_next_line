/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:06:40 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/11 00:32:37 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, char *src)
{
	char	*cpy;

	if (!dst || !src)
		return (0);
	cpy = dst;
	while (*src)
	{
		*cpy = *src;
		cpy++;
		src++;
	}
	*cpy = '\0';
	return (dst);
}

char	*ft_strlcat(char **dst, char *src, int n)
{
	int		len;
	int		i;
	int		j;
	char	*aux;

	aux = NULL;
	if (!dst || !src)
		return (NULL);
	i = ft_strlen(*dst);
	j = -1;
	len = i + n;
	aux = (char *)malloc(sizeof(char) * len + 1);
	if (!aux)
		return (NULL);
	if (*dst)
		ft_strcpy(aux, *dst);
	while (++j < n && src[j])
		aux[i + j] = src[j];
	aux[i + j] = '\0';
	ft_free(dst);
	*dst = aux;
	return (*dst);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (len);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	read_batch(int fd, char *buff)
{
	int	bytes_read;

	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		return (-1);
	}
	buff[bytes_read] = '\0';
	return (bytes_read);
}

void	ft_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	return (NULL);
}
