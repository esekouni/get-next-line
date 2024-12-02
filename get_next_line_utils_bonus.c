/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:54:30 by esekouni          #+#    #+#             */
/*   Updated: 2022/12/02 18:51:36 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

int	ft_strlen(char *ch)
{
	int	i;

	i = 0;
	if (!ch)
		return (0);
	while (ch[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ch;
	int		i;
	int		j;

	i = ft_strlen(s1) + ft_strlen(s2);
	ch = malloc(sizeof(char) * i + 1);
	if (!ch)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		ch[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
		ch[i++] = s2[j++];
	free (s1);
	ch[i] = '\0';
	return (ch);
}

char	*ft_strchr(char *ch, char c)
{
	int		i;
	char	*s;
	int		j;

	i = 0;
	j = 0;
	if (ch == NULL)
		return (NULL);
	while (ch[i] && ch[i] != c)
		i++;
	if (!ch[i] || (ch[i] == c && ch[i + 1] == '\0'))
		return (NULL);
	s = malloc (sizeof(char) * (ft_strlen(ch) - i) + 1);
	if (!s)
		return (NULL);
	i++;
	while (ch[i])
		s[j++] = ch[i++];
	s[j] = '\0';
	return (s);
}
