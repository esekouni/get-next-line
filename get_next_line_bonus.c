/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:54:06 by esekouni          #+#    #+#             */
/*   Updated: 2022/12/09 16:21:28 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

int	checkline(char *ch)
{
	int	i;

	i = 0;
	while (ch[i] != '\0')
	{
		if (ch[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(int fd, char *ch)
{
	int		i;
	char	*s;

	s = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	while (1)
	{
		i = read(fd, s, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (i == -1)
		{
			free(ch);
			free(s);
			return (NULL);
		}
		s[i] = '\0';
		ch = ft_strjoin(ch, s);
		if (checkline(ch) == 1)
			break ;
	}
	free (s);
	return (ch);
}

char	*line(char *ch)
{
	char	*str;
	int		i;

	i = 0;
	while (ch[i] && ch[i] != '\n')
		i++;
	str = malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (ch[i] && ch[i] != '\n')
	{
		str[i] = ch[i];
		i++;
	}
	if (ch[i] == '\n')
	{
		str[i] = ch[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*ch;
	char		*str;
	static char	*s[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = get_line(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	ch = line(s[fd]);
	str = s[fd];
	s[fd] = ft_strchr(str, '\n');
	free(str);
	return (ch);
}
