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

static t_bool	place(t_data *data, t_entry *entry, int index, int *count);

void	init_data(t_data *data)
{
	int	i;

	data->first_entry = false;
	i = 0;
	while (i < MAX_ENTRIES)
	{
		data->entries[i] = NULL;
		i++;
	}
}

void	add_entry(t_data *data, char *key, char *value, size_t key_len)
{
	static int	count = 0;
	t_entry		*entry;
	int			index;

	if (count >= MAX_ENTRIES)
		return ;
	entry = malloc(sizeof(t_entry));
	entry->key = key;
	entry->value = value;
	index = get_index(entry, key_len);
	if (data->entries[index] == NULL)
		data->entries[index] = entry;
	else
	{
		if (place(data, entry, index, &count) == TRUE)
		{
			data->first_entry = true;
			return ;
		}
		free(entry->key);
		free(entry->value);
		free(entry);
	}
	data->first_entry = true;
	count++;
}

static t_bool	place(t_data *data, t_entry *entry, int index, int *count)
{
	int	i;

	i = index;
	while (data->entries[index] != NULL)
	{
		if (data->entries[index]->hashed_key == entry->hashed_key)
		{
			free(data->entries[index]->value);
			free(data->entries[index]->key);
			data->entries[index]->value = entry->value;
			data->entries[index]->key = entry->key;
			free(entry);
			return (TRUE);
		}
		index++;
		if (i == index)
			return (FALSE);
		if (index >= MAX_ENTRIES)
			index = 0;
	}
	data->entries[index] = entry;
	(*count)++;
	return (TRUE);
}

void	clean_up(t_data *data)
{
	u_int32_t	i;
	t_entry		*current;
	t_entry		*temp;

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
