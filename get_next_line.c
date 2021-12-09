/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:25:42 by sel-kham          #+#    #+#             */
/*   Updated: 2021/12/09 03:53:34 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			start;
	int			res_len;
	char		*s;
	static char	*temp_buff;
	static char	*leftover;

	s = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[BUFFER_SIZE] = 0;
	res_len = read(fd, s, BUFFER_SIZE);
	if (res_len == -1)
		return (NULL);
	if (!res_len)
		return (ft_strdup(""));
	start = ft_strchr(s, '\n');
	if (start != -1)
	{
		temp_buff = ft_strjoin(leftover, s, start + 1);
		leftover = ft_substr(s, start + 1, ft_strlen(s) - start);
	}
	else
	{
		leftover = ft_strjoin(leftover, s, res_len);
		get_next_line(fd);
	}
	return (temp_buff);
}