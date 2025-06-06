/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:23:58 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/25 11:15:56 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

int	searcher(t_data *data)
{
	char	*line;
	char	*result;

	ft_putstr_fd("\033[0;32mSEARCH:\033[0m\n", 1);
	line = get_next_line(0, FALSE);
	if (!line || line[0] == '\n')
		return (free(line), EXIT);
	while (line && line[0] != '\n')
	{
		line[ft_strlen(line) - 1] = '\0';
		result = hash_lookup(data, line);
		if (!result)
			error_print(NOT_FOUND, line);
		else
		{
			ft_putstr_fd(result, 1);
			write(1, "\n", 1);
		}
		free(line);
		line = get_next_line(0, FALSE);
	}
	free(line);
	return (EXIT);
}
