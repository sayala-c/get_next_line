/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayala-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 02:17:31 by sayala-c          #+#    #+#             */
/*   Updated: 2026/03/10 02:18:23 by sayala-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		fds[1024];
	char	*line;
	int		num_files;
	int		active_files;
	int		i;

	// 1. Abrir archivos o usar STDIN
	if (argc == 1)
	{
		fds[0] = 0;
		num_files = 1;
	}
	else
	{
		num_files = 0;
		while (num_files < argc - 1 && num_files < 1024)
		{
			fds[num_files] = open(argv[num_files + 1], O_RDONLY);
			if (fds[num_files] < 0)
				perror("Error al abrir archivo");
			num_files++;
		}
	}

	// 2. El bucle de lectura intercalada
	active_files = 1;
	while (active_files)
	{
		active_files = 0;
		i = 0; // Reiniciamos el índice para dar una vuelta a todos los fds
		while (i < num_files)
		{
			if (fds[i] != -1)
			{
				line = get_next_line(fds[i]);
				if (line != NULL)
				{
					printf("[FD %d]: %s", fds[i], line);
					free(line);
					active_files = 1; // Si alguien devuelve algo, el bucle sigue
				}
			}
			i++;
		}
	}

	// 3. Cerrar archivos (excepto stdin que es el fd 0)
	i = 0;
	while (i < num_files)
	{
		if (fds[i] > 0)
			close(fds[i]);
		i++;
	}
	return (0);
}
