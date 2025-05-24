#ifndef HOTRACE_H
#define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

#include "get_next_line_bonus.h"


typedef struct
{
	char*	key;
	int		value;
} entity;

typedef enum e_bool
{
	false,
	true
}	t_bool;


//------------------ UTILS ----------------

char	*ft_strchr(const char *str, int c);

char	*ft_strjoin_free_s1(char *s1, char *s2);

size_t	ft_strlen(const char	*str);

#endif

