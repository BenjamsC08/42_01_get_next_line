/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:47:35 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/19 21:13:25 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	unsigned char	c;
	char			str[2];

	c = 2;
	while (str[1] != 10 || str[1] == 0)
	{
		read(fd, str, 1);
		write(1, str, 1);
	}
	return (0);
}
/*
int main()
{
	int fd;

	fd = open("test.txt", O_RDONLY);

	get_next_line(fd);

	close(fd);
}*/
