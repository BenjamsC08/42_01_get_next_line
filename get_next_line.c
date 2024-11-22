/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:47:35 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/22 13:45:29 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_dup_line(char *s, int n)
{
	int		l_line;
	char	*str;
	char	*src;
	int		nb;
	char	c;

	l_line = ft_len_line(s);
	str = (char *)malloc((l_line + 1) * sizeof(char));
	if (! str)
		return (0);
	nb = 0;
	src = str;
	while (nb != n)
	{
		c = *s;
		if (*s == '\n' || !*s)
			nb++;
		s++;
	}
	(void) c;
	while (*s != '\n')
		*(str++) = *(s++);
	*(str++) = *(s++);
	*str = '\0';
	return (src);
}

char	*get_line(int n, char *buff)
{
	char	*str;
	int		nb;

	nb = 0;
	str = ft_dup_line(buff, n);
	return (str);
}
//2 eme iteration buff == 0
char	*get_next_line(int fd)
{
	char		*str;
	char		*buff;
	static int	n = 0;

	buff = (char *)malloc(BUFF_SIZE, 1);
	if (!buff)
		return (NULL);
	read(fd, buff, BUFF_SIZE);
	printf("%d iteration :\n%s , fd : %d\n", n+1, buff, fd);
	str = get_line(n, buff);
	n++;
	free(buff);
	return (str);
}

int	main(void)
{
	const char	*file_name = "test.txt";
	static int			fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("\nError Opening File!!\n");
		return (1);
	}
	char *str = get_next_line(fd);
	//printf("%s",str);
	free(str);
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
	close(fd);
}
