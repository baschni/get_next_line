/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baschnit <baschnit@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 01:56:38 by baschnit          #+#    #+#             */
/*   Updated: 2024/10/31 06:29:08 by baschnit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define MAX_OPEN_FILES 5000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <stddef.h>

typedef struct s_rlst
{
	char			*str;
	struct s_rlst	*next;
}	t_rlst;

char	*get_next_line(int fd);

#endif