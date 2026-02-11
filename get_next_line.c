/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:28:00 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/11 20:11:53 by pedrohe3         ###   ########.fr       */
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
/*
void	ft_putstr(char *buff)
{
	int	i;

	i = 0;
	if (!buff)
	{
		printf("(null)\n");
		return ;
	}
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

int	main(void)
{

	int	fd = open("/home/pedro/42/get_next_line/test", O_RDONLY);
	int	fd2 = open("/home/pedro/42/get_next_line/test2", O_RDONLY);
	int	fd3 = open("/home/pedro/42/get_next_line/test3", O_RDONLY);
	char	*res;
	int	depth = 0;

	do
	{
		res = NULL;
		printf("\n\nCalling get_next_line - depth (%d)\n", depth);
		res = get_next_line(fd);
		depth++;
		if (!res)
			break;
		printf("len: %d | res: ", ft_strlen(res));
		ft_putstr(res);
		//if (depth == 2)
		//	break ;
	} while(depth < 11);
	close(fd);
	close(fd2);
	printf("End of program\n");
	return (0);
}
*/
