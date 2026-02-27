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
    char    *tmp;
    char    *buffer;
    int read_content;//el size_t normal es unsignes y con ss es signed

    buffer = malloc((BUFFER_SIZE + 1)*(sizeof(char)));//reservamos el espacio de memoria donde guardar lo que leeremos con read
    if (!buffer)
        return (NULL);
    read_content = 1;
    while (!content || (!ft_strchr(content, '\n') && read_content != 0))// read content nos indica si estamos o no al final del documento, es decir, si algo para seguir leyendo, si es distinto a 0 significa que hat algo por leer, ya que son el num de bytes, siempre que haya al menos un byte, entra en el bucle, despues le daremos el valor de la funcion read para saber los bytes exactos que ha leido, que nos serviran de indice para poner el null mas tarde.
    {
        read_content = read(fd, buffer, BUFFER_SIZE);//read devuelve el numero de bytes leidos
        if (read_content == -1)
            return (free (buffer), NULL);
        buffer[read_content] = '\0';
        content = gnl_strjoin (content, buffer);
    }
    return (free(buffer), content);
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
    line = dup_gnl(content, line);
    if (content[i] == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return (line);
}

char    *get_update_content(char *content, char *line)
{
    int line_len;
    int new_content_len;
    int content_len;
    int i;
    char    *new_content;

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

char    *get_next_line(int fd)
{
    static char *content;//los static recuerdan y guardan el contenido de la variable incluse despues del return. Con una variable normal se borra
    char        *line;
    content = get_content(fd, content);//funcion aux para leer el contenido del fd e inicializar
    if(!content)
        return(NULL);
    line = get_line(content);//funcion aux para leer y guardar hasta el primer /n encontrado en content
    if (!line)
        return (free(content), NULL);
    content = get_update_content(content, line);
    return (line);
}

