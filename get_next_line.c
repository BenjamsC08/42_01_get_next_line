/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:47:35 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/24 11:11:32 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_line(t_list *storage, char **ptr_line)
{
	int	i;
	int	j;

	if (storage == NULL)
		return ;
	alloc_size_line(ptr_line, storage);
	if (! *ptr_line)
		return ;
	j = 0;
	while (storage)
	{
		i = 0;
		while (storage->content[i])
		{
			(*ptr_line)[j++] = storage->content[i];
			if (!storage->content[i])
				return ;
			i++;
		}
		storage = storage->next;
	}
	(*ptr_line)[j] = 0;
}

void	store_line(t_list **storage, char *buff)
{
	int		i;
	t_list	*new;
	t_list	*last;

	new = (t_list *)malloc(sizeof(t_list));
	if (! new)
		return ;
	new->next = NULL;
	new->content = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
	if (! new->content)
		return ;
	i = 0;
	while (buff[i])
	{
		new->content[i] = buff[i];
		i++;
	}
	new->content[i] = 0;
	if (*storage == NULL)
	{
		*storage = new;
		return ;
	}
	last = ft_lstlast(*storage);
	last->next = new;
}

void	read_line(int fd, t_list **storage)
{
	char	*buff;
	int		nb_r;

	nb_r = 1;
	while (! found_nwline(*storage) && nb_r)
	{
		buff = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
		if (!buff)
			return ;
		nb_r = read(fd, buff, BUFF_SIZE);
		buff[nb_r] = 0;
		if (*storage == NULL && nb_r == 0)
		{
			free(buff);
			return ;
		}
		store_line(storage, buff);
		free(buff);
		return ;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*storage = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFF_SIZE <= 0 )
		return (NULL);
	read_line(fd, &storage);
	if (storage == NULL)
		return (NULL);
	get_line(storage, &line);
	return (line);
}

int	main(void)
{
	const char			*file_name = "test.txt";
	static int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("\nError Opening File!!\n");
		return (1);
	}
	char *str = get_next_line(fd);
	printf("%s",str);
	free(str);
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
	close(fd);
}
