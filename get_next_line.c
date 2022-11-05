/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:56:13 by aelkhali          #+#    #+#             */
/*   Updated: 2022/11/05 13:58:22 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*re_n_store(int fd, char **sv)
{
	int		i_readed;
	char	*buf;

	i_readed = 1;
	buf = malloc (BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (i_readed != 0 && !ft_strchr(*sv, '\n'))
	{
		i_readed = read(fd, buf, BUFFER_SIZE);
		if (i_readed == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i_readed] = '\0';
		*sv = ft_strjoin(*sv, buf);
	}
	free(buf);
	return (*sv);
}

static char	*line_extractor(char *str)
{
	unsigned int	len;
	char			*extracted_line;

	if (!str)
		return (NULL);
	if (!ft_strchr(str, '\n'))
		return (str);
	len = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n')) + 1;
	extracted_line = ft_substr(str, 0, len);
	return (extracted_line);
}

static char	*extract_mod(char *str)
{
	char			*mod_extract;
	unsigned int	start;
	size_t			len;

	if (!ft_strchr(str, '\n'))
		return (NULL);
	len = ft_strlen(ft_strchr(str, '\n')) - 1;
	start = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n'));
	mod_extract = ft_substr(str, start, len);
	return (mod_extract);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	container = re_n_store(fd, &container);
	line = line_extractor(container);
	tmp = extract_mod(container);
	free(container);
	container = tmp;
	return (line);
}
