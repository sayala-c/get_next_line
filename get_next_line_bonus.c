/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:46:42 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/12 03:48:45 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_content(int fd, char *content)
{
	char	*buffer;
	int		read_content;

	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	read_content = 1;
	while (!content || (!ft_strchr(content, '\n') && read_content != 0))
	{
		read_content = read(fd, buffer, BUFFER_SIZE);
		if (read_content == -1)
			return (free (buffer), free(content), NULL);
		buffer[read_content] = '\0';
		content = gnl_strjoin (content, buffer);
	}
	return (free(buffer), content);
}

char	*get_line(char *content)
{
	int		i;
	char	*line;

	i = 0;
	if (!content[i])
		return (NULL);
	while (content[i] != '\n' && content[i] != '\0')
		i++;
	if (content[i] == '\n')
		line = malloc((i + 2) * (sizeof(char)));
	else
		line = malloc((i + 1) * (sizeof(char)));
	if (!line)
		return (NULL);
	line = dup_gnl(content, line);
	if (content[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_update_content(char *content, char *line)
{
	int		line_len;
	int		new_content_len;
	int		content_len;
	int		i;
	char	*new_content;

	line_len = ft_strlen(line);
	content_len = ft_strlen(content);
	new_content_len = content_len - line_len;
	if (new_content_len == 0)
		return (free(content), NULL);
	new_content = malloc((new_content_len + 1) * sizeof(char));
	if (!new_content)
		return (free(content), NULL);
	i = 0;
	while (content[i] && new_content_len > i)
	{
		new_content[i] = content[line_len + i];
		i++;
	}
	new_content[i] = '\0';
	return (free(content), new_content);
}

char	*get_next_line(int fd)
{
	static char	*content[10240];
	char		*line;

	if (fd < 0 || fd >= 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	content[fd] = get_content(fd, content[fd]);
	if (!content[fd])
		return (NULL);
	line = get_line(content[fd]);
	if (!line)
	{
		free(content[fd]);
		content[fd] = NULL;
		return (NULL);
	}
	content[fd] = get_update_content(content[fd], line);
	return (line);
}
