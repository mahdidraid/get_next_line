/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:50:58 by edraidry          #+#    #+#             */
/*   Updated: 2022/11/04 20:45:11 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *str)
{
	while ((str != NULL) && (*str != '\0'))
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*chr;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		*s1 = '\0';
	}
	i = 0;
	chr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!chr)
		return (NULL);
	while (s1[i])
	{
		chr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		chr[i++] = s2[j++];
	chr[i] = '\0';
	free(s1);
	return (chr);
}
