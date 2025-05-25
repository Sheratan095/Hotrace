/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 23:09:52 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/25 11:15:56 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

// static void	insert_entry(t_data *data, t_entry *entry);

t_data	*init_data(void)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	data->first_entry = false;
	data->first_line = NULL;
	data->mode = INSERTION;
	i = 0;
	while (i < MAX_ENTRIES)
	{
		data->entries[i] = NULL;
		i++;
	}
	return (data);
}

// index = get_index(entry); Calculate the index based on the hashed key
// entry->next = data->entries[index]; Point to the existing chain
// data->entries[index] = entry;        Insert at the head of the linked list
t_data	*add_entry(t_data *data, char *key, char *value)
{
	t_entry		*entry;
	int			index;

	entry = malloc(sizeof(t_entry));
	entry->key = malloc(ft_strlen(key) + 1 * sizeof(char));
	entry->value = malloc(ft_strlen(value) + 1 * sizeof(char));
	ft_strlcpy(entry->key, key, ft_strlen(key) + 1);
	ft_strlcpy(entry->value, value, ft_strlen(value) + 1);
	index = get_index(entry);
	if (data->entries[index] == NULL)
	{
		data->entries[index] = entry;
		entry->next = NULL;
	}
	else
	{
		entry->next = data->entries[index];
		data->entries[index] = entry;
	}
	data->first_entry = true;
	return (data);
}

void	clean_up(t_data *data)
{
	int		i;
	t_entry	*current;
	t_entry	*temp;

	i = 0;
	while (i < MAX_ENTRIES)
	{
		if (data->entries[i] != NULL)
		{
			current = data->entries[i];
			while (current != NULL)
			{
				temp = current;
				current = current->next;
				free(temp->key);
				free(temp->value);
				free(temp);
			}
			data->entries[i] = NULL;
		}
		i++;
	}
	free(data);
}
