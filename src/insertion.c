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

static void	parse_line(t_data *data, char *line, char *key);

int	insertion(t_data *data)
{
	char		*line;
	char		*key;

	line = data->first_line;
	key = NULL;
	data->is_even = TRUE;
	if (!line)
		line = get_next_line(0, FALSE);
	parse_line(data, line, key);
	if (data->is_even == FALSE)
		return (SYNTAX_ERROR);
	if (!line)
		return (EXIT);
	ft_putstr_fd("\033[0;32mSEARCH:\033[0m\n", 1);
	line = get_next_line(0, FALSE);
	if (!line || line[0] == '\n')
		return (free(line), EXIT);
	data->first_line = line;
	return (0);
}

static void	parse_line(t_data *data, char *line, char *key)
{
	size_t	line_len;
	size_t	key_len;

	while (line && line[0] != '\n')
	{
		data->is_even = !data->is_even;
		line_len = ft_strlen(line);
		line[line_len - 1] = '\0';
		if (data->is_even == FALSE)
		{
			// free(key);
			key = line;
			key_len = line_len;
		}
		else
		{
			add_entry(data, key, line, key_len - 1, line_len - 1);
			// free(key);
			key = NULL;
			// free(line);
		}
		line = get_next_line(0, FALSE);
	}
	free(line);
	free(key);
}
