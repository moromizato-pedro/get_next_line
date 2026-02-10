/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:28:00 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/10 16:02:47 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*next_line;
	//static char	*next_line;
	int			i;
	char		*rest;

	if (fd < 0)
		return (NULL);
	next_line = NULL;
	rest = NULL;
	i = -1;
	if (ft_strlen(buff) <= 0)
		if (read_batch(fd, buff) <= 0)
			return (NULL);
	while (buff[++i])
	{
		if (buff[i] == '\n')
		{
			if (ft_strlen(buff) > 0)
				ft_strlcat(&next_line, buff, i + 1);
			ft_strcpy(buff, buff + i + 1);
			return (next_line);
		}
	}
	ft_strlcat(&next_line, buff, ft_strlen(buff));
	buff[0] = '\0';
	//get_next_line(fd);
	rest = get_next_line(fd);
	ft_strlcat(&next_line, rest, ft_strlen(rest));
	return (ft_free(&rest), next_line);
	//return (next_line);
}
/*
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
		//if (depth == 2)
		//	break ;
	} while(res && depth < 11);
	close(fd);
	printf("End of program\n");
	return (0);
}
*/
