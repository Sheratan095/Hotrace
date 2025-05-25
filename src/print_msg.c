/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:45:35 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/25 11:15:56 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

void	error_print(int error, char *keyword)
{
	write(2, "\033[0;31m", 7);
	if (error == MALLOC_ERROR)
		write(2, "Malloc failed\n", 14);
	else if (error == SYNTAX_ERROR)
		write(2, "Syntax error\n", 13);
	else if (error == NOT_FOUND)
	{
		write(2, keyword, ft_strlen(keyword));
		write(2, ": Not found.\n", 13);
	}
	else if (error == NO_ARGS)
	{
		write(2, "This program doesn't take any arguments.\n", 42);
		write(2, "Example: ./hotrace\n", 20);
	}
	write(2, "\033[0m", 4);
}

void	usage(void)
{
	ft_putstr_fd("\033[0;34mUsage:\033[0m ./hotrace\n\n", 1);
	ft_putstr_fd("This program implements a minimal search engine.\n\n", 1);
	ft_putstr_fd("Input format (via standard input):\n", 1);
	ft_putstr_fd("1. First phase — insertion:\n", 1);
	ft_putstr_fd("   - Enter a keyword on a line.\n", 1);
	ft_putstr_fd("   - Enter the associated value on the next line.\n", 1);
	ft_putstr_fd("   - Repeat for as many pairs as needed.\n", 1);
	ft_putstr_fd("   - End this phase with an empty line.\n\n", 1);
	ft_putstr_fd("1. Second phase — search:\n", 1);
	ft_putstr_fd("   - Enter one keyword per line to search for.\n", 1);
	ft_putstr_fd("   - The program prints the value ", 1);
	ft_putstr_fd("or '<keyword>: Not found.'\n\n", 1);
	ft_putstr_fd("   - The program ends when it encounters **two", 1);
	ft_putstr_fd(" consecutive empty lines**.\n\n", 1);
	ft_putstr_fd("Example:\n", 1);
	ft_putstr_fd("---------\n", 1);
	ft_putstr_fd("Input:\n", 1);
	ft_putstr_fd("keyword-1\nvalue-1\nkeyword-2\nvalue-2\n\n", 1);
	ft_putstr_fd("keyword-1\nkeyword-2\nkeyword-3\n\n", 1);
	ft_putstr_fd("Output:\n", 1);
	ft_putstr_fd("value-1\nvalue-2\nkeyword-3: Not found.\n", 1);
	ft_putstr_fd("\n\n\033[0;32mINPUT:\033[0m\n", 1);
}
