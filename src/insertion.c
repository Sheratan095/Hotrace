/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:57:52 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/24 14:57:54 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Hotrace.h"

int insertion(t_data *data)
{
	char	*line;

	line = data->first_line;
	if (!line)
		line = get_next_line(0, FALSE);
	while (line && line[0] != '\n')
	{
		//
		free(line);
		line = get_next_line(0, FALSE);
	}
	if (line && line[0] == '\n')
	{
		line = get_next_line(0, FALSE);
		if (!line || line[0] == '\n')
			return (EXIT);
		data->first_line = line;
	}
	return (0);
}
