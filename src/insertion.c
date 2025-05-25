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

static int	parse_line(t_data *data, char *line, char *key);

int	insertion(t_data *data)
{
	char		*line;
	char		*key;

	key = NULL;
	line = NULL;
	data->is_even = TRUE;
	if (parse_line(data, line, key) == EXIT)
		return (EXIT);
	if (data->is_even == FALSE)
		return (SYNTAX_ERROR);
	return (EXIT);
}

static int	parse_line(t_data *data, char *line, char *key)
{
	size_t	line_len;
	size_t	key_len;

	line = get_next_line(0, FALSE);
	while (line && line[0] != '\n')
	{
		data->is_even = !data->is_even;
		line_len = ft_strlen(line);
		line[line_len - 1] = '\0';
		if (data->is_even == FALSE)
		{
			key = line;
			//free(line);
			key_len = line_len;
		}
		else
		{
			add_entry(data, key, line, key_len - 1, line_len - 1);
			key = NULL;
		}
		line = get_next_line(0, FALSE);
	}
	free(key);
	if (!line)
		return (EXIT);
	return (free(line), 0);
}
