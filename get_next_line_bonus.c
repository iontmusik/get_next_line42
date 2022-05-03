/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:52:50 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/28 16:32:36 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
