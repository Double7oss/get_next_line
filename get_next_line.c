/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kadd <hel-kadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:58:24 by hel-kadd          #+#    #+#             */
/*   Updated: 2022/11/06 17:58:24 by hel-kadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_line(char *str)
{
    int i;
    char *s;
    if (!str)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    s = malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        s[i] = str[i];
        i++;
    }
}

char *ft_read_from_file(int fd, char *str)
{
    int i;
    char *buff;
    if (!str)
        return (NULL);
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    
}

char *get_next_line(int fd)
{
    
}