/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:32:52 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/27 21:30:22 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_save_static(char *sta);
char	*ft_line(char *str);
char	*ft_read(int fd, char *sta);

#endif