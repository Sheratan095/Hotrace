/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:57:52 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/25 21:27:32 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

int	insertion(t_data *data, char *key, char *line)
{
	size_t	line_len;
	size_t	key_len;

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
			add_entry(data, key, line, key_len - 1);
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
