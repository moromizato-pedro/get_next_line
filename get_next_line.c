/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:28:00 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/17 20:43:12 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*next_line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line = NULL;
	i = 1;
	while (1)
	{
		if (!buff[0])
			i = read_batch(fd, buff);
		if (i < 0)
			return (free(next_line), NULL);
		else if (i == 0)
			return (next_line);
		i = 0;
		while (buff[i] && buff[i - 1] != '\n')
			i++;
		ft_strncat(&next_line, buff, i);
		if (buff[i - 1] == '\n')
			return (ft_strcpy(buff, buff + i), next_line);
		buff[0] = '\0';
	}
}
