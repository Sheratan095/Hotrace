
#include "Hotrace.h"

// static void	insert_entry(t_data *data, t_entry *entry);

t_data	init_data(void)
{
	t_data	data;

	data.mode = insertion;
	return (data);
}

void	add_entry(t_data *data, char *key, char *value)
{
	(void)key;
	(void)value;
	(void)data;

	t_entry	entry;
	// entry.hashed_key = NULL; // Placeholder for hashed key
	ft_strlcpy(entry.key, key, ft_strlen(key)); // Assuming key is a string
	ft_strlcpy(entry.value, value, ft_strlen(value)); // Assuming key is a string

	// insert_entry(data, NULL);
}

// static void	insert_entry(t_data *data, t_entry *entry)
// {
// 	(void)data;
// 	(void)entry;
// 	// uint32_t	hash;
// 	// uint32_t	index;

// 	// if (!data || !entry)
// 	// 	return ;
// 	// hash = MurmurHash2(entry->key, ft_strlen(entry->key), 0);
// 	// index = hash % MAX_ENTRIES;
// 	// data->entries[index] = entry;
// }
