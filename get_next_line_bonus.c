/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kadd <hel-kadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:10:07 by hel-kadd          #+#    #+#             */
/*   Updated: 2022/11/11 22:42:06 by hel-kadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *ft_get_line(char *str)
{
    char *s;
    int i;

    i = 0;
    if (!str[i])
        return (NULL);
    while (str[i] && str[i] != '\n')
        i++;
    s = (char *)malloc(sizeof(char) * (i + 2));
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

char *ft_line(char *s)
{
    int i;
    int j;
    char *str;

    i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    if (!s[i])
    {
        free(s);
        return (NULL);
    }
    str = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
    if (!str)
        return (NULL);
    i++;
    j = 0;
    while (s[i])
        str[j++] = s[i++];
    str[j] = '\0';
    free(s);
    return (str);
}

char *ft_read_save(int fd, char *str)
{
    int cut;
    char *buff;

    cut = 1;

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
    static char *str[4096];
    char *l;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    str[fd] = ft_read_save(fd, str[fd]);
    if (!str[fd])
        return (NULL);
    l = ft_get_line(str[fd]);
    str[fd] = ft_line(str[fd]);
    return (l);
}