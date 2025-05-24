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

// 2^18 entries - good balance between size and performance
# define MAX_ENTRIES 500009

enum e_parsing_code
{
	CONTINUE,
	MALLOC_ERROR,
	SYNTAX_ERROR,
	EXIT,
};
typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef enum e_mode
{
	INSERTION,
	SEARCH,
}	t_mode;

typedef struct s_entry
{
	char			*hashed_key;
	char			*key;
	char			*value;
	struct	s_entry	*next;
}	t_entry;

typedef struct s_data
{
	t_entry	*entries[MAX_ENTRIES];
	t_mode	mode;
	char	*first_line;
}	t_data;

//------------------ DATA ----------------

t_data		init_data(void);

void		add_entry(t_data *data, char *key, char *value);

//------------------ UTILS ----------------

void		*ft_memcpy(void *dest, const void *src, size_t n);

size_t		ft_strlcpy(char *dst, const char *src, size_t size);

char		*ft_strchr(const char *str, int c);

char		*ft_strjoin_free_s1(char *s1, char *s2);

size_t		ft_strlen(const char	*str);

//----------------- PARSING ---------------

int			parser(t_data *data);
int			searcher(t_data *data);
int			insertion(t_data *data);
void		error_print(int error);

#endif
