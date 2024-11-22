/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:24:41 by kosakats          #+#    #+#             */
/*   Updated: 2024/11/20 21:40:17 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
}

int	main(void)
{
	char	*line;
	int		i;

	int fd, fd2, fd3;
	fd = open("text.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	while (1)
	{
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd2));
		printf("%s", get_next_line(fd3));
		if (!line)
		{
			free(line);
			break ;
		}
		free(line);
	}
	close(fd);
	return (0);
}
