/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:12:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/27 21:57:10 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_save_static(char *sta)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (sta[i] && sta[i] != '\n')
		i++;
	if (!sta[i])
	{
		free(sta);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(sta) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (sta[i] != '\0')
		str[j++] = sta[i++];
	str[j] = '\0';
	free(sta);
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
