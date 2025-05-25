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

void	init_data(t_data *data)
{
	int		i;

	data->first_entry = false;
	i = 0;
	while (i < MAX_ENTRIES)
	{
		data->entries[i] = NULL;
		i++;
	}
}

t_data	*add_entry(t_data *data, char *key, char *value, size_t key_len, size_t value_len)
{
	t_entry		*entry;
	int			index;
	(void)key_len;
	(void)value_len;

	entry = malloc(sizeof(t_entry));
	entry->key = key;
	entry->value = value;
	// ft_strlcpy(entry->key, key, key_len + 1);
	// ft_strlcpy(entry->value, value, value_len + 1);
	index = get_index(entry, key_len);
	if (data->entries[index] == NULL)
		data->entries[index] = entry;
	else
	{
		while (data->entries[index] != NULL)
		{
			if (data->entries[index]->hashed_key == entry->hashed_key)
			{
				free(data->entries[index]->value);
				data->entries[index]->value = value;
				free(entry);
				return (data);
			}
			index++;
			if (index >= MAX_ENTRIES)
				index = 0;
		}
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
			temp = current;
			free(temp->key);
			free(temp->value);
			free(temp);
			data->entries[i] = NULL;
		}
		i++;
	}
	get_next_line(0, TRUE);
}
