/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:30:31 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/25 11:15:56 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

int	parser(t_data *data)
{
	int	parsing_code;

	data->mode = INSERTION;
	parsing_code = CONTINUE;
	while (parsing_code == CONTINUE)
	{
		if (data->mode == INSERTION)
		{
			parsing_code = insertion(data);
			data->mode = SEARCH;
		}
		else
		{
			parsing_code = searcher(data);
			data->mode = INSERTION;
		}
	}
	get_next_line(0, TRUE);
	if (parsing_code == MALLOC_ERROR || parsing_code == SYNTAX_ERROR)
		return (error_print(parsing_code, NULL), parsing_code);
	return (0);
}
