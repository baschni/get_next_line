/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:36:35 by baschnit          #+#    #+#             */
/*   Updated: 2024/10/06 22:36:35 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		s++;
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;

	a = (unsigned char) c;
	while (*s)
	{
		if (a == *s)
			return ((char *) s);
		s++;
	}
	if (!*s && a == '\0')
		return ((char *) s);
	return (NULL);
}

char	*ft_stpcpy_strdup(char *dst, const char *s)
{
	char	*dup;

	if (dst)
	{
		while (*s)
		{
			*dst = *s;
			s++;
			dst++;
		}
		*dst = '\0';
		return (dst);
	}
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	dst = dup;
	if (!dup)
		return (NULL);
	while (*s)
	{
		*dup = *s;
		s++;
		dup++;
	}
	*dup = '\0';
	return (dst);
}

// char	*ft_stpcpy(char *dst, const char *src)
// {
// 	while (*src)
// 	{
// 		*dst = *src;
// 		src++;
// 		dst++;
// 	}
// 	*dst = '\0';
// 	return (dst);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*dup;
// 	char	*start;

// 	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
// 	start = dup;
// 	if (!dup)
// 		return (NULL);
// 	while (*s)
// 	{
// 		*dup = *s;
// 		s++;
// 		dup++;
// 	}
// 	*dup = '\0';
// 	return (start);
// }

char	*join_list_to_str(t_rlst *start)
{
	size_t	length;
	t_rlst	*i;
	char	*str;

	if (!start)
		return (ft_stpcpy_strdup(NULL, ""));
	i = start;
	length = ft_strlen(start->str);
	while (i->next)
	{
		i = i->next;
		length += ft_strlen(i->str);
	}
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = start;
	str = ft_stpcpy_strdup(str, i->str);
	while (i->next)
	{
		i = i->next;
		str = ft_stpcpy_strdup(str, i->str);
	}
	return (str - length);
}

char	*free_list(t_rlst **rest)
{
	t_rlst	*current;
	t_rlst	*next;

	if (!*rest)
		return (NULL);
	current = *rest;
	while (current->next)
	{
		next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
	free(current->str);
	free(current);
	*rest = NULL;
	return (NULL);
}
