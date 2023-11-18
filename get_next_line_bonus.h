/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraidry <edraidry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:36:19 by edraidry          #+#    #+#             */
/*   Updated: 2022/11/06 11:36:31 by edraidry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>

char	*get_next_line(int fd);
int		ft_strchr(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
#endif