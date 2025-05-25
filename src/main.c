/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:03:40 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/25 10:24:47 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	if (argc != 1)
		return (1);
	usage();
	data = init_data();
	parser(data);
	clean_up(data);
	return (0);
}
