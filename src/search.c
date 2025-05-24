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

#include "Hotrace.h"
#include <stdio.h>

int	searcher(t_data *data)
{
	char	*line;
	char	*result;

	line = data->first_line;
	while (line && line[0] != '\n')
	{
		line[ft_strlen(line) - 1] = '\0';
		result = hash_lookup(data, line);
		if (!result)
			error_print(NOT_FOUND, line);
		else
			ft_putstr_fd(result, 1);
		line = get_next_line(0, FALSE);
	}
	line = get_next_line(0, FALSE);
	if (!line || line[0] == '\n')
		return (free(line), EXIT);
	data->first_line = line;
	return (0);
}
