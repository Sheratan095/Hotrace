
#include "Hotrace.h"

// static void	insert_entry(t_data *data, t_entry *entry);

t_data	init_data(void)
{
	t_data	data;

	data.mode = INSERTION;
	return (data);
}

void	add_entry(t_data *data, char *key, char *value)
{
	t_entry		entry;
	int			index;

	ft_strlcpy(entry.key, key, ft_strlen(key)); // Assuming key is a string
	ft_strlcpy(entry.value, value, ft_strlen(value)); // Assuming key is a strin
	index = get_index(&entry); // Calculate the index based on the hashed key

	// se 
	if (data->entries[index] == NULL)
	{
		data->entries[index] = &entry;
	}
}

