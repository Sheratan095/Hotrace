
#include "Hotrace.h"

// static void	insert_entry(t_data *data, t_entry *entry);

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mode = INSERTION;
	int i = 0;
	while (i < MAX_ENTRIES)
	{
		data->entries[i] = NULL;
		i++;
	}
	return (data);
}

t_data	*add_entry(t_data *data, char *key, char *value)
{
	t_entry		*entry;
	int			index;

	entry = malloc(sizeof(t_entry));
	entry->next = NULL;
	entry->key = malloc(ft_strlen(key) + 1 * sizeof(char));
	entry->value = malloc(ft_strlen(value) + 1 * sizeof(char));
	ft_strlcpy(entry->key, key, ft_strlen(key) + 1); // Assuming key is a string
	ft_strlcpy(entry->value, value, ft_strlen(value) + 1); // Assuming key is a strin
	index = get_index(entry); // Calculate the index based on the hashed key

	// se 
	// if (data->entries[index] == NULL)
	// {
		data->entries[index] = entry;
	// }
	// else
	// {
	// 	data->entries[index]->next = entry;
	// }

	return (data);
}

