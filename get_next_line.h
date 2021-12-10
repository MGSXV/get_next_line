/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:26:18 by sel-kham          #+#    #+#             */
/*   Updated: 2021/12/10 02:55:22 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# include<fcntl.h>
# include<stdlib.h>

char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2, int len);
char	*ft_strdup(const char *s1);

#endif