/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 07:44:24 by aelkhali          #+#    #+#             */
/*   Updated: 2022/11/04 14:11:31 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	char	cas_c;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	cas_c = (char )c;
	while (s[i] && s[i] != cas_c)
		i++;
	if (s[i] == '\0' && cas_c != s[i])
		return (NULL);
	return ((char *)&s[i]);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	char	*recall;
	int		i;

	i = 0;
	if (!s1)
	{
		s1 = malloc (1);
		s1[0] = 0;
	}
	if (!s2)
		return (NULL);
	new_str = malloc ((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new_str)
		return (NULL);
	recall = new_str;
	while (s1[i])
			*new_str++ = s1[i++];
	while (*s2)
		*new_str++ = *s2++;
	*new_str = '\0';
	free(s1);
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
	{
		s = malloc(1);
		if (!s)
			return (NULL);
		s[0] = '\0';
		return (s);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_str = malloc (len + 1);
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
