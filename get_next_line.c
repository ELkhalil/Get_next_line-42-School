/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:56:13 by aelkhali          #+#    #+#             */
/*   Updated: 2022/11/04 14:21:38 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*re_n_store(int fd)
{
	char static	*save;
	char		*buf;
	int			i_read;

	i_read = 1;
	save = NULL;
	buf = malloc(sizeof(char ) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (i_read != 0 && !ft_strchr(save, '\n'))
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
	free(buf);
	return (save);
}

char	*extract_line(char *sv)
{
	char	*extracted_line;
	char	*tmp;
	size_t	line_len;

	if (!*sv)
	{
		free(sv);
		return (NULL);
	}
	line_len = ft_strlen(sv) - ft_strlen(ft_strchr(sv, '\n'));
	extracted_line = ft_substr(sv, 0, line_len + 1);
	tmp = ft_substr(sv, line_len + 1, ft_strlen(ft_strchr(sv, '\n')));
	free(sv);
	sv = tmp;
	free(tmp);
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
