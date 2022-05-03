/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:52:50 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/28 16:33:54 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>*/

int	ft_strchr(char *str, int c)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = ft_strlen(str);
	if (!str)
		return (0);
	while (i < j)
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strchrtwo(char *str, int c)
{
	ssize_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_read(int fd, char *sta)
{
	int		buff;
	char	*str;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (0);
	buff = 1;
	while (!ft_strchr(sta, '\n') && (buff != 0))
	{
		buff = read(fd, str, BUFFER_SIZE);
		if (buff == -1)
		{
			free(str);
			return (NULL);
		}
		str[buff] = '\0';
		sta = ft_strjoin(sta, str);
	}
	free(str);
	return (sta);
}

char	*get_next_line(int fd)
{
	static char	*sta[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	sta[fd] = ft_read(fd, sta[fd]);
	if (!sta[fd])
		return (NULL);
	line = ft_line(sta[fd]);
	sta[fd] = ft_save_static(sta[fd]);
	return (line);
}

/* int	main(void)
{
	char	*line;
	int		fd1;
 	int		fd2;
	int		fd3; 
	int		i;

	fd1 = open("text.txt", O_RDONLY);
   	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);  
 	i = 1;
	while (i < 5)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line); 
  		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line); 
		i++;
	}
 	close(fd1); 
  	close(fd2);
	close(fd3);  
	return (0); 
}  */

int	main(void)
{
	char	*line;
	int		fd1;

	fd1 = open("text.txt", O_RDONLY);
 	line = get_next_line(fd1);
	printf("line [01]: %s\n", line);
	line = get_next_line(fd1);
	printf("line [02]: %s\n", line);
	line = get_next_line(fd1);
	printf("line [03]: %s\n", line);
	line = get_next_line(fd1);
	printf("line [04]: %s\n", line);
	line = get_next_line(fd1);
	printf("line [05]: %s\n", line);
 	close(fd1);
	return (0); 
}
