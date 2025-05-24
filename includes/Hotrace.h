/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:09:41 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/24 11:15:51 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>

# include "get_next_line_bonus.h"

// max size_t
# define MAX_ENTRIES 4294967295

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_mode
{
	insertion,
	search
}	t_mode;

typedef struct s_entry
{
	char	*hashed_key;
	char	*key;
	char	*value;
}	t_entry;

typedef struct s_data
{
	t_entry	*entries[MAX_ENTRIES];
	t_mode	mode;
}	t_data;

//------------------ DATA ----------------

t_data	init_data(void);

t_entry *create_entry(char *key, int value);

//------------------ UTILS ----------------


char	*ft_strchr(const char *str, int c);

char	*ft_strjoin_free_s1(char *s1, char *s2);

size_t	ft_strlen(const char	*str);

#endif
