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

#include "includes/Hotrace.h"


//
void	parse_entries() 
{

}

int	parser(t_data *data)
{
	t_bool	mode;
	int		result;

	mode = INSERTION;
	result = CONTINUE;
	while (result == CONTINUE)
	{
		if (mode == INSERTION)
			result = insert(data);
		else
			result = searcher(data);
		++mode;
	}
	if (result == MALLOC_ERROR || result == SYNTAX_ERROR)
		return (error_print(result));
	return (0);
}