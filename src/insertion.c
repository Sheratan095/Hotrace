/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:57:52 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/25 13:36:25 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

static int	parse_line(t_data *data);

int	insertion(t_data *data)
{
	return (parse_line(data));
}

static int	parse_line(t_data *data)
{
	size_t	line_len;
	size_t	key_len;
	char	*line = NULL;
	char	*key = NULL;

	line = get_next_line(0, FALSE);
	while (line && line[0] != '\n')
	{
		line_len = ft_strlen(line);
		line[line_len - 1] = '\0';
		if (key == NULL)
		{
			key = line;
			key_len = line_len;
		}
		else
		{
			add_entry(data, key, line, key_len - 1, line_len - 1);
			key = NULL;
		}
		line = get_next_line(0, FALSE);
	}
	if (line[0] == '\n')
		free(line);
	if (key)
		return (free(key), SYNTAX_ERROR);
	return (EXIT);
}
