/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:40:27 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/10 00:46:40 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_content(int fd, char *content);
char	*get_line(char *content);
char	*get_next_line(int fd);
char	*get_update_content(char *content, char *line);
char	*gnl_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*dup_gnl(char *content, char *line);
size_t	ft_strlen(const char *s);

#endif
