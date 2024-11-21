/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:47:35 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/20 17:25:36 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	*get_pos_len(int fd)
{
	int		tab[BUFF_SIZE];
	int		nb;
	int		i;
	char	buff[BUFF_SIZE];

	read(fd, buff, BUFF_SIZE);
	while (buff[i])
	{
		
	}
}

char  *get_line(int fd, int n)
{
	int	**tab;

	tab = get_pos_len(fd);
}

char	*get_next_line(int fd)
{
	char		*str;
	static int	n = 0;

	str = get_next_line(n);
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
	close(fd);
}
