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

int	somme_tab(int *tab_s, int *tab_e)
{
	int	k;
	int	*tab;

	k = 0;
	tab = tab_s;
	while (tab != tab_e)
		k += *(tab++);
	return (k);
}

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
	*(tab++) = 0;
	read(fd, buff, sizeof(buff));
	while (buff[i])
	{
		if (buff[i] == '\n')
		{
			*tab = (++i) - *(tab - somme_tab(tab_pos, tab));
			tab++;
		}
		i++;
	}
	*(tab) = i;
	return (tab_pos);
}
/*
char	*ft_fd_dup(int fd, int start, int length)
{
	char	buff[BUFF_SIZE];
	char	*str;
	char	*so;
	int		i;

	read(fd, buff, BUFF_SIZE);
	str = (char *)malloc(length + 3);
	if (! str)
		return (NULL);
	so = str;
	i = (int)start;
	while ((i - start) < length)
	{
		str[i - start] = buff[i];
		i++;
	}
	str[i - start] = '\0';
	return (str);
}
*/
char	*get_next_line(int fd)
{
	static int	n = 0;
	int			*tab;
	int			i;
	//char		*str;

	i = 0;
	tab = count_char(fd);
	if (tab[n + 1] == -1)
	{
		free(tab);
		return (NULL);
	}
	//str = ft_fd_dup(fd, tab[n], tab[n + 1] - tab[n]);
	//if (!str)
	//	return (NULL);
	printf("%d\n", tab[n]);
	free(tab);
	//free(str);
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
	close(fd);
}
