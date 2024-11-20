/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_next_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:09:50 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/20 12:58:19 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	extract_line(int fd)
{
	char		*buff;
	int			l;
	static int	n = 1;

	i = 0;
	l = 0;
	buff = malloc(4096);
	read(fd, buff, sizeof(buff));
	while (l != n || ! *buff)
	{
		if (*buff == '\n')
			l++;
		if (l == n - 1)
			write(1, buff, 1);
		buff++;
	}
	n++;
	free(buff);
	return ;
}

int	main(void)
{
	const char	*file_name = "test.txt";
	int			fd;

	fd = open(file_name, O_RDWR);
	if (fd == -1)
	{
		printf("\nError Opening File!!\n");
		return (1);
	}
	extract_line(fd);
	extract_line(fd);
	extract_line(fd);
	extract_line(fd);
	extract_line(fd);
	close(fd);
}
