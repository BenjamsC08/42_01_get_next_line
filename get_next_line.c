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

void	del_line(t_list **stash)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_all_storage(*stash);
	*stash = clean_node;
}

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
			if (storage->content[i] == '\n')
			{
				(*ptr_line)[j++] = storage->content[i];
				return ;
			}
			(*ptr_line)[j++] = storage->content[i++];
		}
		storage = storage->next;
	}
	(*ptr_line)[j] = 0;
}

void	stock_line(t_list **storage, char *buff, int nb_bytes)
{
	int		i;
	t_list	*new;
	t_list	*last;

	new = (t_list *)malloc(sizeof(t_list));
	if (! new)
		return ;
	new->next = NULL;
	new->content = (char *)malloc((nb_bytes + 1) * sizeof(char));
	if (! new->content)
		return ;
	i = 0;
	while (buff[i] && i < nb_bytes)
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
	int		nb_bytes;

	nb_bytes = 1;
	while (!found_nwline(*storage) && nb_bytes)
	{
		buff = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
		if (!buff)
			return ;
		nb_bytes = read(fd, buff, BUFF_SIZE);
		buff[nb_bytes] = 0;
		if (*storage == NULL && nb_bytes == 0)
		{
			free(buff);
			return ;
		}
		stock_line(storage, buff, nb_bytes);
		free(buff);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*storage = NULL;
	char			*line;

	if (fd < 0 || BUFF_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_line(fd, &storage);
	if (storage == NULL)
		return (NULL);
	get_line(storage, &line);
	del_line(&storage);
	if (!*line)
	{
		free_all_storage(storage);
		storage = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
/*
int	main(void)
{
	const char			*file_name = "test.txt";
	static int			fd;
	char				*str;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("Error Opening File '%s'\n", file_name);
		return (1);
	}
	while (1)
	{
		str = get_next_line(fd);	
		if (str == NULL)
			break ;
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}*/
