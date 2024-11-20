/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <benjamsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:45:28 by benjamsc          #+#    #+#             */
/*   Updated: 2024/11/20 15:16:50 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_nzero(void *s, size_t n)
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)s;
	i = -1;
	while (++i < n)
		ptr[i] = -1;
	return ;
}

void	*ft_nalloc(size_t nmemb, size_t size)
{
	char			*ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_nzero(ptr, nmemb * size);
	return (ptr);
}
