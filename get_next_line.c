/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:56:13 by aelkhali          #+#    #+#             */
/*   Updated: 2022/11/03 13:14:18 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	cas_c;
	int		i;

	if (!s)
		return (0);
	i = 0;
	cas_c = (char )c;
	while (s[i] && s[i] != cas_c)
		i++;
	if (s[i] == '\0' && cas_c != s[i])
		return (NULL);
	return ((char *)&s[i]);
}

char	*get_next_line(int fd)
{
	char 		*str_reader;
	static char	*storage;
	char		*line;
	int			i;
	int			i_readed;

	str_reader = NULL;
	line = NULL;
	i_readed = 1;
	storage = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || !read(fd, str_reader, BUFFER_SIZE))
		return (NULL);
	str_reader = malloc(BUFFER_SIZE + 1);
	if (!str_reader)
		return (NULL);
	while (i_readed >= 0 && !ft_strchr(storage, '\n'))
	{
		i_readed = read(fd, str_reader, BUFFER_SIZE);
		str_reader[i_readed] = '\0';
		storage = ft_strjoin(str_reader, storage);
		if (!ft_strchr(str_reader, '\n'))
			return(str_reader);
	}
	while (storage[i] && storage[i] != '\n')
		i++;
	line = ft_substr(storage, 0, i + 1);
	storage = ft_substr(storage , i, ft_strlen(ft_strchr(storage,'\n')));
	return (line);
}
