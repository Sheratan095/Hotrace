/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:57:52 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/24 23:10:16 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

static void	parse_line(t_data *data, char *line, char *key, t_bool_val *even);

int	insertion(t_data *data)
{
	char		*line;
	char		*key;
	t_bool_val	even;

	line = data->first_line;
	key = NULL;
	even.val = TRUE;
	if (!line)
		line = get_next_line(0, FALSE);
	parse_line(data, line, key, &even);
	if (even.val == FALSE)
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

static void	parse_line(t_data *data, char *line, char *key, t_bool_val *even)
{
	while (line && line[0] != '\n')
	{
		++((*even).val);
		line[ft_strlen(line) - 1] = '\0';
		if ((*even).val == FALSE)
			key = line;
		else
		{
			add_entry(data, key, line);
		}
		line = get_next_line(0, FALSE);
	}
}
