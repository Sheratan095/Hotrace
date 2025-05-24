/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:03:40 by maceccar          #+#    #+#             */
/*   Updated: 2025/05/24 11:15:56 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"


/*
	1)	Capire cosa passare
	2)	insert
	3)	searcher
	4)	stampa errori
*/
int	main(void)
{
	t_data	data;

	data = init_data();
	add_entry(&data, "key1", "value1");
	// if (parser(&data) == 1)
		//error
	return (0);
}	
