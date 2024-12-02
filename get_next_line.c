/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:48:45 by esekouni          #+#    #+#             */
/*   Updated: 2022/12/09 16:21:19 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cheackline(char *ch)
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
	char	*b;
	int		i;

	b = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (1)
	{
		i = read(fd, b, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (i == -1)
		{
			free(ch);
			free(b);
			return (NULL);
		}
		b[i] = '\0';
		ch = ft_strjoin(ch, b);
		if (cheackline(b) == 1)
			break ;
	}
	free(b);
	return (ch);
}

char	*line(char *ch)
{
	int		i;
	char	*s;

	i = 0;
	while (ch[i] != '\0' && ch[i] != '\n')
		i++;
	s = malloc(sizeof(char) * i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (ch[i] != '\0' && ch[i] != '\n')
	{
		s[i] = ch[i];
		i++;
	}
	if (ch[i] == '\n')
	{
		s[i] = ch[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	char		*ch;
	char		*str;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = get_line(fd, s);
	if (!s)
		return (NULL);
	ch = line(s);
	str = s;
	s = ft_strchr(str, '\n');
	free(str);
	return (ch);
}
