/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:56:13 by aelkhali          #+#    #+#             */
/*   Updated: 2022/11/04 10:18:44 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*re_n_store(int fd)
{
	int			i_read;
	char		*buf;
	char static	*save;

	i_read = 1;
	save = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(save, '\n') && i_read != 0)
	{
		i_read = (int )read(fd, buf, BUFFER_SIZE);
		if (i_read == -1)
		{
			free(buf);
			free(save);
			return (NULL);
		}
		buf[i_read] = '\0';
		save = ft_strjoin(save, buf);
	}
	if (!ft_strchr(save, '\n'))
		return (save);
	free(buf);
	return (save);
}

char	*extract_line(char *str)
{
	char	*extracted_line;
	char	*tmp;
	size_t	line_len;

	line_len = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n'));
	extracted_line = malloc(line_len + 1);
	if (!extracted_line)
		return (NULL);
	ft_strlcpy(extracted_line, str, line_len + 1);
	tmp = ft_substr(str, line_len, ft_strlen(ft_strchr(str, '\n')));
	free(str);
	str = ft_strdup(tmp);
	return (extracted_line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = extract_line(re_n_store(fd));
	return (line);
}
