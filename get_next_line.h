/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kadd <hel-kadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:30:31 by hel-kadd          #+#    #+#             */
/*   Updated: 2022/11/05 15:30:31 by hel-kadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char *ft_get_line(char *str);
char *get_next_line(int fd);
char *ft_read_save(int fd, char *str);
#endif