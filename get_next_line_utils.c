/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:06:40 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/01/26 19:38:43 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, char *src)
{
	char *cpy;

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

char	*ft_strcat(char **dst, char *src)
{
	int	len;
	char	*aux;

	aux = NULL;
	if (!src)
		return (*dst);
	len = ft_strlen(*dst) + ft_strlen(src);
	//printf("len: %d\n", len);
	if (*dst)
		aux = ft_strdup(*dst);
	ft_free(dst);
	*dst = (char *)calloc(sizeof(char), len + 1);
	//printf("dst: %s -> ", *dst);
	if (aux)
		ft_strcpy(*dst, aux);
	//printf("%s -> ", *dst);
	ft_strcpy(*dst + ft_strlen(*dst), src);
	//printf("%s\n", *dst);
	return (ft_free(&aux), *dst);
}

char	*ft_strncat(char **dst, char *src, int n)
{
	int	len;
	int	i;
	int	j;
	char	*aux;

	aux = NULL;
	if (!src)
		return (NULL);
	i = ft_strlen(*dst);
	j = 0;
	len = ft_strlen(*dst) + n;
	if (*dst)
		aux = ft_strdup(*dst); 
	ft_free(dst);
	*dst = (char *)calloc(sizeof(char), len + 1);
	if (aux)
		ft_strcpy(*dst, aux);
	//printf("i: %d | j: %d | n: %d | len: %d\ndst: %s\nsrc: %s\n", i, j, n, len, *dst, src);
	while (j < n)
	{
		(*dst)[i + j] = src[j];
		//printf("[%d](dst, src): (%c, %c)\n", j, (*dst)[i + j], src[j]);
		j++;
	}
	(*dst)[i + j] = '\0';
	return (ft_free(&aux), *dst);
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

int	read_batch(int fd, char *buff, char **buff_cpy)
{
	int	bytes_read;

	bytes_read = read(fd, buff, BUFFER_SIZE);
	buff[bytes_read] = '\0';
	/*if (buff[bytes_read] == '\0')
		printf("[%d]: %s\\0\n", bytes_read, buff);
	else if (buff[bytes_read] == '\n')
		printf("[%d]: %s\\n", bytes_read, buff);
	else
		printf("[%d]: %s?", bytes_read, buff);
	*/
	if (*buff_cpy)
		ft_free(buff_cpy);
	*buff_cpy = ft_strdup(buff);
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

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		len;
	int		i;

	ptr = NULL;
	len = ft_strlen(s);
	i = -1;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	while (++i < len + 1)
		ptr[i] = s[i];
	return (ptr);
}

void	putstr(char *buff)
{
	int	i;

	i = 0;
	printf("\"");
	while(1)
	{
		if (buff[i] == '\n')
			printf("\\n");
		else if (buff[i] == '\0')
		{
			printf("\\0");
			break ;
		}
		else
			printf("%c", buff[i]);
		i++;
	}
	printf("\"\n");
}
