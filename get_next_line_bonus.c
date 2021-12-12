/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:21:02 by sel-kham          #+#    #+#             */
/*   Updated: 2021/12/11 19:02:14 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_check_next_line(char *leftover)
{
	char	*res;
	int		start;
	int		i;

	if (!leftover)
		return (NULL);
	i = -1;
	start = ft_strchr(leftover, '\n');
	if (start == -1)
		return (ft_strdup(leftover));
	res = malloc((start + 2) * sizeof(char));
	if (!res)
		return (NULL);
	while (++i < start)
		res[i] = leftover[i];
	res[i] = '\n';
	res[i + 1] = 0;
	return (res);
}

static char	*ft_remove_last_line(char *leftover)
{
	int		start;
	char	*lo;

	start = ft_strchr(leftover, '\n');
	if (!leftover || start == -1 || ft_strlen(leftover) - start == 1)
		return (free(leftover), NULL);
	lo = ft_strdup(leftover + start + 1);
	free(leftover);
	return (lo);
}

char	*get_next_line(int fd)
{
	int			res_len;
	char		*tmp_buff;
	char		*s;
	static char	*leftover[1024];

	tmp_buff = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!s)
		return (NULL);
	while (ft_strchr(leftover[fd], '\n') == -1)
	{
		res_len = read(fd, s, BUFFER_SIZE);
		if (res_len <= 0)
			break ;
		s[res_len] = 0;
		leftover[fd] = ft_strjoin(leftover[fd], s, res_len);
	}
	tmp_buff = ft_check_next_line(leftover[fd]);
	leftover[fd] = ft_remove_last_line(leftover[fd]);
	return (free(s), tmp_buff);
}
