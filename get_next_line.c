/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:28:00 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/01/26 19:35:43 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char	*buff_cpy;
	char	*next_line;
	int	i;

	if (fd < 0)
		return (NULL);
	buff_cpy = NULL;
	next_line = NULL;
	i = 0;
	if (ft_strlen(buff) <= 0)
	{
		if (read_batch(fd, buff, &buff_cpy) <= 0 )
			return (ft_free(&buff_cpy), NULL);
	}
	else
		buff_cpy = ft_strdup(buff);
	while (ft_strlen(buff_cpy + i) >= 0)
	{
		if (buff[i] == '\n')
		{
			if (ft_strlen(buff) > 0)
				ft_strncat(&next_line, buff, i + 1);
			else
				printf("\n");
			ft_strcpy(buff, buff + i + 1);
			return (ft_free(&buff_cpy), next_line);
		}
		else if (buff[i] == '\0')
		{
			ft_strcat(&next_line, buff);
			//ft_free(&buff_cpy);
			if (read_batch(fd, buff, &buff_cpy) <= 0)
				return (ft_free(&buff_cpy), next_line);
			i = 0;
			continue ;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{

	int	fd = open("/home/pedro/42/get_next_line/test", O_RDONLY);
	char	*res;
	int	depth = 0;

	do
	{
		res = NULL;
		printf("\n\nCalling get_next_line\n");
		res = get_next_line(fd);
		if (!res)
			break;
		printf("len: %d | res: ", ft_strlen(res));
		putstr(res);
		depth++;
	} while(res && depth < 11);
	close(fd);
	printf("End of program\n");

	//get_next_line(0);
	return (0);
}

*/
