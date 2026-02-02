/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrohe3 <pedrohe3@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:29:55 by pedrohe3          #+#    #+#             */
/*   Updated: 2026/01/12 19:34:20 by pedrohe3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strcat(char **dst, char *src);
char	*ft_strncat(char **dst, char *src, int n);
int	ft_strlen(char *str);
int	read_batch(int fd, char *buff, char **buff_cpy);
void	ft_free(char **ptr);
char	*ft_strdup(char *s);
void	putstr(char *str);

