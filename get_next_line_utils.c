/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 07:44:24 by aelkhali          #+#    #+#             */
/*   Updated: 2022/11/03 13:11:34 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen( char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strdup( char *s1)
{
	char	*copied_str;
	size_t	lentgh;
	int		i;

	i = 0;
	lentgh = ft_strlen(s1);
	copied_str = malloc (lentgh + 1);
	if (!copied_str)
		return (NULL);
	while (s1[i])
	{
		copied_str[i] = s1[i];
		i++;
	}
	copied_str[i] = '\0';
	return (copied_str);
}

size_t	ft_strlcpy(char *dst,  char *src, size_t dstsize)
{
	size_t	src_length;

	src_length = ft_strlen(src);
	if (dstsize > 0)
	{
		while (*src && --dstsize)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_length);
}

char	*ft_strjoin(char *str_read, char *storage)
{
	char	*new_str;
	char	*recall;

	if (!str_read && !storage)
		return (NULL);
	if (!storage)
		return(ft_strdup(str_read));
	if (!str_read)
		return (ft_strdup(storage));
	new_str = malloc ((ft_strlen(str_read) + ft_strlen(storage)) + 1);
	recall = new_str;
	if (!new_str)
		return (NULL);
	while (*storage)
		*new_str++ = *storage++;
	while (*str_read)
		*new_str++ = *str_read++;
	*new_str = '\0';
	free(str_read);
	return (recall);
}

char	*ft_substr(char  *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub_str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_str = malloc (len + 1);
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
