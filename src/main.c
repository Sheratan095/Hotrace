/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:03:40 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/24 23:10:16 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

/*
	1)	Capire cosa passare
	2)	insert
	3)	searcher
	4)	stampa errori
*/
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
