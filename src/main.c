/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:03:40 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/25 11:15:56 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

int	main(int argc, char **argv)
{
	t_data	data; // Declare data as an automatic variable instead of a pointer

	(void)argv;
	if (argc != 1)
		return (error_print(NO_ARGS, NULL), 1);
	usage();
	init_data(&data); // Initialize the data structure directly
	handle_data(&data); // Pass a pointer to the structure
	clean_up(&data); // Clean up allocations within the structure
	return (0);
}
