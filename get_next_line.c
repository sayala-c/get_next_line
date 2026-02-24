/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:58:17 by sayala-c          #+#    #+#             */
/*   Updated: 2026/02/19 22:00:22 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_content(int fd, char *content)//leemos el hasta el buffer_size y lo guardamos en una variable.
{
    char    *buffer;
    ssize_t read_content;//el size_t normal es unsignes y con ss es signed

    buffer = malloc((BUFFER_SIZE + 1)*(sizeof(char)));//reservamos el espacio de memoria donde guardar lo que leeremos con read
    if (!buffer)
        return (NULL);
    while ()
        read_content = read(fd, buffer, BUFFER_SIZE);//read devielve el numero de bytes leidos
    if (read_content = -1)
    {
        free (buffer);
        return (NULL);
    }
    ft_strjoin
{
char    *get_line(char *content)
{
    int i;
    char    *line;

    i = 0;
    if (!content)
        return(NULL);
    while (content[i] != '\n' && content[i] !='\0')
        i++;
    if (content[i] == '\n')
        line = malloc((i + 2) * (sizeof(char)));
    else
        line = malloc((i + 1) * (sizeof(char)));
    if (!line)
        return (NULL);
    i = 0;
    while (content[i] != '\n' && content[i] != '\0')
        line[i++] = content[i++];
    if (content[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}
char    *get_next_line(int fd)
{
    static char *content;//los static recuerdan y guardan el contenido de la variable incluse despues del return. Con una variable normal se borra
    char        *line;
    content = get_content(fd, content);//funcion aux para leer el contenido del fd e inicializar
    if(!content)
        return(NULL);
    line = get_line(content);//funcion aux para leer y guardar hasta el primer /n encontrado en content
    content = get_update_content(content);
    return (line);
}
