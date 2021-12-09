/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kham <sel-kham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 23:26:04 by sel-kham          #+#    #+#             */
/*   Updated: 2021/12/09 01:48:50 by sel-kham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	while (++i < n)
		*((char *)(dst + i)) = *((char *)(src + i));
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*target;
	size_t	i;
	size_t	target_len;

	i = -1;
	target_len = ft_strlen(s1) + 1;
	target = (char *) malloc(target_len * sizeof(char));
	if (!target)
		return (0);
	ft_memcpy(target, s1, target_len);
	return (target);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start >= s_len)
		return (ft_strdup(""));
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

int	ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	if (!c)
		return (i);
	while (s[++i])
		if (s[i] == (char) c)
			return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char const *s2, int len)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 /*|| !s2*/)
		return (ft_substr(s2, 0, len));
	s1_len = ft_strlen(s1);
	s2_len = len;
	i = -1;
	result = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result = ft_memcpy(result, s1, s1_len);
	while (++i < s2_len)
		result[i + s1_len] = s2[i];
	result[s1_len + s2_len] = '\0';
	return (result);
}