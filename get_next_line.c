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
    char *s;
    int i;

    i = 0;
    if (!str)
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    s = (char *)malloc(sizeof(char) * (i + 1));
    if (!s)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
    {
        s[i] = str[i];
        i++;
    }
    if (str[i] == '\n')
    {
        s[i] = str[i];
        i++;
    }
    s[i] = '\0';
    return (s);
}

char *ft_read_save(int fd, char *str)
{
    int cut;
    char *buff;

    cut = 1;
    if (!str)
        return (NULL);
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
        return (NULL);
    while (!ft_strchr(str, '\n') && cut != 0)
    {
        cut = read(fd, buff, BUFFER_SIZE);
        if (cut == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[cut] = '\0';
        str = ft_strjoin(str, buff);
    }
    free(buff);
    return (str);
}

char *get_next_line(int fd)
{
    char *str;
   static char *l;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = ft_read_save(fd, str);
    if (!str)
        return (0);
    l = ft_get_line(str);
    return (l);
}