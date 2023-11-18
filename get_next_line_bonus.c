/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:33:01 by edraidry          #+#    #+#             */
/*   Updated: 2022/11/07 20:29:11 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_line(char *lien)
{
	int		i;
	char	*str;

	if (!*lien)
		return (NULL);
	i = 0;
	while (lien[i] && lien[i] != '\n')
		i++;
	str = (char *) malloc (i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (lien[i] && lien[i] != '\n')
	{
		str[i] = lien[i];
		i++;
	}
	if (lien[i] == '\n')
		str[i++] = '\n';
	str [i] = '\0';
	return (str);
}

char	*ft_n_line(char *lien)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (lien[i] && lien[i] != '\n')
		i++;
	if (!lien[i])
	{
		free(lien);
		return (NULL);
	}
	str = (char *) malloc (ft_strlen(lien) - i + 1);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (lien[i])
		str[j++] = lien[i++];
	str [j] = '\0';
	free(lien);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	int			byte;
	char		*bufer;
	static char	*line_str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bufer = (char *)malloc(BUFFER_SIZE + 1);
	if (!bufer)
		return (NULL);
	byte = 1;
	while (ft_strchr (line_str[fd]) && byte)
	{
		byte = read (fd, bufer, BUFFER_SIZE);
		if (byte == -1)
			return (free (bufer), NULL);
		bufer [byte] = '\0';
		line_str [fd] = ft_strjoin (line_str [fd], bufer);
	}
	free(bufer);
	line = ft_line(line_str[fd]);
	line_str[fd] = ft_n_line(line_str[fd]);
	return (line);
}
