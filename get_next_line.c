/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:47:35 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/20 15:21:17 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	*count_char(int fd)
{
	char			buff[BUFF_SIZE];
	int				i;
	int				*tab_pos;
	int				*tab;

	tab_pos = (int *)ft_nalloc(BUFF_SIZE, sizeof(int));
	if (! tab_pos)
		return (NULL);
	tab = tab_pos;
	i = 0;
	read(fd, buff, sizeof(buff));
	while (buff[i])
	{
		if (buff[i] == '\n')
			*(tab++) = i;
		i++;
	}
	*(tab) = i;
	return (tab_pos);
}

char	*get_next_line(int fd)
{
	static int	n = 0;
	int			*tab;

	tab = count_char(fd);
	if (tab[n + 1] == -1)
	{
		free(tab);
		return (NULL);
	}
	free(tab);
	n++;
	return (NULL);
}

int	main(void)
{
	const char	*file_name = "test.txt";
	int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("\nError Opening File!!\n");
		return (1);
	}
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
}
