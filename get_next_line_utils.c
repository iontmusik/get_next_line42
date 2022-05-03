/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtorre-s <jtorre-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:12:07 by jtorre-s          #+#    #+#             */
/*   Updated: 2022/04/27 20:07:40 by jtorre-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;
	size_t		lencom;

	i = 0;
	if (!s)
		return (NULL);
	lencom = ft_strlen(s);
	if (len > lencom)
		len = lencom;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (start < lencom)
	{
		while (i < len)
			str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*d;
	int		i;

	i = 0;
	d = malloc(ft_strlen(s1) + 1);
	if (d == NULL)
		return (NULL);
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
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
