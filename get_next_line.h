/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:51:11 by aelkhali          #+#    #+#             */
/*   Updated: 2022/11/04 14:10:27 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
char	*re_n_store(int fd);
size_t   ft_strlen(char *s);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_substr(char  *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst,  char *src, size_t dstsize);
char	*ft_strchr(char *s, int c);

#endif