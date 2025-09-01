/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 00:00:30 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/22 00:00:30 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_splitfromnew(char **text, char *newline, char **keep)
{
	char	*temp;
	size_t	text_len;
	size_t	newpos;

	text_len = ft_strlen(*text);
	newpos = newline - *text;
	if (newpos + 1 < text_len)
		*keep = ft_strdup(newline + 1);
	else
		*keep = NULL;
	temp = ft_substr(*text, 0, newpos + 1);
	free(*text);
	*text = temp;
	if (!*text || **text == '\0')
	{
		free(*text);
		return (0);
	}
	return (1);
}

static int	ft_readline(int fd, char **newline, char **text, char **keep)
{
	ssize_t		bytes_read;
	char		*buffer;

	free(*keep);
	*newline = ft_strchr(*text, '\n');
	while (!*newline)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (ft_strlen(*text) > 0)
			{
				*newline = *text + ft_strlen(*text);
				return (1);
			}
			return (0);
		}
		ft_realloc(&*text, buffer);
		free(buffer);
		*newline = ft_strchr(*text, '\n');
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*text;
	char		*newline;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!keep)
		text = ft_strdup("");
	else
	{
		text = ft_strdup(keep);
		if (!text)
			return (free(keep), NULL);
	}
	if (keep && !*text && BUFFER_SIZE > 2)
		return (free(keep), free(text), NULL);
	if (!ft_readline(fd, &newline, &text, &keep))
		return (free(text), NULL);
	if (!ft_splitfromnew(&text, newline, &keep))
		return (free(keep), NULL);
	return (text);
}
