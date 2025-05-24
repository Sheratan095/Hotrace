
#include "Hotrace.h"

void	insert_entry(t_data *data, t_entry *entry)
{
	(void)data;
	(void)entry;
	// uint32_t	hash;
	// uint32_t	index;

	// if (!data || !entry)
	// 	return ;
	// hash = MurmurHash2(entry->key, ft_strlen(entry->key), 0);
	// index = hash % MAX_ENTRIES;
	// data->entries[index] = entry;
}

t_entry *create_entry(char *key, int value)
{
	(void)key;
	(void)value;
	// t_entry	*entry;

	// //entry = (t_entry *)malloc(sizeof(t_entry));
	// if (!entry)
	// 	return (NULL);
	// entry->key = key;
	// entry->value = value;
	return (NULL);
}

t_data	init_data(void)
{
	t_data	data;

	data.mode = insertion;
	return (data);
}