/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:48:12 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/10 00:50:39 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s2)
		return (free(s1), NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			s3[i] = s1[i];
			i++;
		}
	}
	i = ft_strlen(s1);
	j = 0;
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (free(s1), s3);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == ((char)c))
			return ((char *)&s[i]);
		i++;
	}
	if ((s[i] == 0) && (s[i] == ((char)c)))
		return ((char *)&s[i]);
	return (NULL);
}

char	*dup_gnl(char *content, char *line)
{
	int	i;

	i = 0;
	while (content[i] != '\n' && content[i])
	{
		line[i] = content[i];
		i++;
	}
	return (line);
}
