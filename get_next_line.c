/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:28:00 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/02/10 14:41:47 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*next_line;
	int			i;
	int			bytes_read;
	//char		*rest;

	if (fd < 0)
		return (NULL);
	next_line = NULL;
	//rest = NULL;
	i = 0;
	if (ft_strlen(buff) <= 0)
		if (read_batch(fd, buff) <= 0)
			return (NULL);
	/*while (buff[i])
	{
		if (buff[i] == '\n')
		{
			if (ft_strlen(buff) > 0)
				ft_strlcat(&next_line, buff, i + 1);
			ft_strcpy(buff, buff + i + 1);
			return (next_line);
		}
		i++;
	}
	// Removing the following lines from inside the while
	// 		The last attempt was to avoid calling read_batch again, and just call the 
	// 		function again and let it deal with the case when the buffer reaches an end
	ft_strlcat(&next_line, buff, ft_strlen(buff));
	buff[0] = '\0';
	rest = get_next_line(fd);
	if (rest)
		ft_strlcat(&next_line, rest, ft_strlen(rest));
	return (next_line);
	*/
	while (1)
	{
		if (buff[i] == '\n')
		{
			if (ft_strlen(buff) > 0)
				ft_strlcat(&next_line, buff, i + 1);
			ft_strcpy(buff, buff + i + 1);
			return (next_line);
		}
		else if (buff[i] == '\0')
		{
			ft_strlcat(&next_line, buff, ft_strlen(buff));
			bytes_read = read_batch(fd, buff);
			if (bytes_read == 0)
				return (next_line);
			else if (bytes_read < 0)
				return (ft_free(&next_line), NULL);
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
		if (depth == 2)

	} while(res && depth < 11);
	close(fd);
	printf("End of program\n");

	//get_next_line(0);
	return (0);
}

*/
