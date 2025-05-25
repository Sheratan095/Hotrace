/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:09:41 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/25 11:15:56 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>

# include "get_next_line_bonus.h"

// 2^18 entries - good balance between size and performance
# define MAX_ENTRIES 240009
// # define MAX_ENTRIES 5

enum e_parsing_code
{
	MALLOC_ERROR,
	SYNTAX_ERROR,
	NOT_FOUND,
	NO_ARGS,
	EXIT,
};

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_entry
{
	u_int32_t		hashed_key;
	char			*key;
	char			*value;
}	t_entry;

typedef struct s_data
{
	t_entry	*entries[MAX_ENTRIES];
	t_bool	first_entry;
}	t_data;

//------------------ DATA ----------------

void		init_data(t_data *data);

t_data		*add_entry(t_data *data, char *key, char *value, size_t key_len, size_t value_len);

int			get_index(t_entry *entry, size_t key_len);

char		*hash_lookup(t_data *data, char *key);

uint32_t	MurmurHash2( const void *key, int len, uint32_t seed );

void		clean_up(t_data *data);

//------------------ UTILS ----------------

void		*ft_memcpy(void *dest, const void *src, size_t n);

size_t		ft_strlcpy(char *dst, const char *src, size_t size);

char		*ft_strchr(const char *str, int c);

char		*ft_strjoin_free_s1(char *s1, char *s2);

size_t		ft_strlen(const char *str);

void		ft_putstr_fd(char *s, int fd);

void		*ft_bzero(void *dest, size_t count);

void		*ft_calloc(size_t nitems, size_t size);

void		*ft_memset(void *dest, int c, size_t count);

//----------------- PARSING ---------------

int			handle_data(t_data *data);
int			searcher(t_data *data);
int			insertion(t_data *data);
void		error_print(int error, char *keyword);
void		usage(void);

#endif
