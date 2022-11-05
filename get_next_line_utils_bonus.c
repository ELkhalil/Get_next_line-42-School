/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:22:16 by aelkhali          #+#    #+#             */
/*   Updated: 2022/11/05 15:37:12 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	char	c_c;
	int		i;

	c_c = (char )c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c_c)
		i++;
	if (s[i] == '\0' && s[i] != c)
		return (NULL);
	return ((char *)&s[i]);
}

size_t	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (*s++)
		i++;
	return (i);
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
	char	*new_sv;
	char	*recall;
	int		i;

	i = 0;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	new_sv = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_sv)
		return (NULL);
	recall = new_sv;
	while (s1[i])
		*new_sv++ = s1[i++];
	while (*s2)
		*new_sv++ = *s2++;
	*new_sv = '\0';
	free(s1);
	return (recall);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*sub_str;

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
