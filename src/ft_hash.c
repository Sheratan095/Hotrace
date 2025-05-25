/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:35:32 by cwannhed          #+#    #+#             */
/*   Updated: 2025/05/25 11:15:56 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"

uint32_t	mur_switch(uint32_t h, unsigned char *data, int len, uint32_t m)
{
	if (len == 3)
		h ^= data[2] << 16;
	if (len >= 2)
		h ^= data[1] << 8;
	if (len >= 1)
	{
		h ^= data[0];
		h *= m;
	}
	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;
	return (h);
}

uint32_t	murmurhash2(const void *key, int len, uint32_t seed)
{
	uint32_t		m;
	uint32_t		h;
	uint32_t		k;
	unsigned char	*data;

	m = 0x5bd1e995;
	h = seed ^ len;
	data = (unsigned char *)key;
	while (len >= 4)
	{
		k = *(uint32_t *)data;
		k *= m;
		k ^= k >> 24;
		k *= m;
		h *= m;
		h ^= k;
		data += 4;
		len -= 4;
	}
	return (mur_switch(h, data, len, m));
}

int	get_index(t_entry *entry, size_t key_len)
{
	entry->hashed_key = murmurhash2(entry->key, key_len, MAX_ENTRIES);
	return (entry->hashed_key % MAX_ENTRIES);
}

char	*hash_lookup(t_data *data, char *key)
{
	t_entry		target_entry;
	t_entry		*found_entry;
	int			index;
	int			i;

	if (!data || !key || data->first_entry == false)
		return (NULL);
	target_entry.key = key;
	index = get_index(&target_entry, ft_strlen(key));
	i = index;
	found_entry = data->entries[index];
	if (found_entry != NULL
		&& found_entry->hashed_key == target_entry.hashed_key)
		return (found_entry->value);
	while (found_entry)
	{
		if (found_entry->hashed_key == target_entry.hashed_key)
			return (found_entry->value);
		if (++index >= MAX_ENTRIES)
			index = 0;
		if (i == index)
			return (NULL);
		found_entry = data->entries[index];
	}
	return (NULL);
}
