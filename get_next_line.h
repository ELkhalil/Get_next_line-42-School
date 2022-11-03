/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhali <aelkhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:51:11 by aelkhali          #+#    #+#             */
/*   Updated: 2022/11/03 10:01:22 by aelkhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*get_next_line(int fd);
size_t	ft_strlen( char *s);
char	*ft_strjoin(char  *s1, char  *s2);
char	*ft_substr(char  *s, unsigned int start, size_t len);
char	*ft_strdup( char *s1);
size_t	ft_strlcpy(char *dst,  char *src, size_t dstsize);

#endif