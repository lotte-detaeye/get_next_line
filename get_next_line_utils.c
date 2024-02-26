/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-taey <lde-taey@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:35:08 by lde-taey          #+#    #+#             */
/*   Updated: 2024/01/28 12:50:28 by lde-taey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	if (s == NULL)
		return (0);
	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_strdup(const char *s)
{
	char	*newstr;
	size_t	length;
	size_t	i;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
	{
		newstr = (char *)malloc(sizeof(char));
		newstr[0] = '\0';
		return (newstr);
	}
	else
		length = ft_strlen(s) + 1;
	newstr = (char *)malloc(length * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < length)
	{
		newstr[i] = s[i];
		i++;
	}
	newstr[length] = '\0';
	return (newstr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	strl;

	if (!s)
		return (NULL);
	strl = ft_strlen(s);
	if (strl < start)
		return (ft_strdup(""));
	if (start + len < strl)
		newstr = (char *)malloc((len + 1) * sizeof(char));
	else
		newstr = (char *)malloc((strl - start + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		newstr[i] = s[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	if (!s)
		return (NULL);
	ch = c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (ch == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*newstr;
	size_t			i;
	size_t			j;

	if (!s2)
		return (NULL);
	newstr = malloc(((ft_strlen(s1)) + ft_strlen(s2) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}
