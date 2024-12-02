/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esekouni <esekouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:54:14 by esekouni          #+#    #+#             */
/*   Updated: 2022/12/09 16:37:39 by esekouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<stdlib.h>
# include<unistd.h>
# include<limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		checkline(char *ch);
char	*get_line(int fd, char *ch);
char	*line(char *ch);
char	*get_next_line(int fd);
int		ft_strlen(char *ch);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *ch, char c);

#endif
