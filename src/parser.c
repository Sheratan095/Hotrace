/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:30:31 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/24 11:30:38 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

int	parser(t_data *data)
{
	int		result;

	data->mode = INSERTION;
	result = CONTINUE;
	while (result == CONTINUE)
	{
		if (data->mode == INSERTION)
		{
			result = insertion(data);
			data->mode = SEARCH;
		}
		else
		{
			result = searcher(data);
			data->mode = INSERTION;
		}
	}
	get_next_line(0, TRUE);
	if (result == MALLOC_ERROR || result == SYNTAX_ERROR)
		return (error_print(result, NULL), result);
	return (0);
}