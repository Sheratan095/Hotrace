/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:23:58 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/24 14:43:38 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Hotrace.h"
#include <stdio.h>

int	searcher(t_data *data)
{
	char	*line;

	line = data->first_line;
	while (line && line[0] != '\n')
	{
		//if lookup! == AAAAAAAAAAAAAAAAAA
		//	error...
		printf("Search: line is %s", line);
		line = get_next_line(0, FALSE);
	}
	line = get_next_line(0, FALSE);
	if (!line || line[0] == '\n')
		return (free(line), EXIT);
	data->first_line = line;
	return (0);
}
