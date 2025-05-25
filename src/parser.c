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

int	handle_data(t_data *data)
{
	int	parsing_code;

	parsing_code = insertion(data);
	if (parsing_code == MALLOC_ERROR || parsing_code == SYNTAX_ERROR)
		return (error_print(parsing_code, NULL), parsing_code);
	parsing_code = searcher(data);
	if (parsing_code == MALLOC_ERROR || parsing_code == SYNTAX_ERROR)
		return (error_print(parsing_code, NULL), parsing_code);
	return (0);
}
