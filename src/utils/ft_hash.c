/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebartol <lebartol@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 11:35:32 by lebartol          #+#    #+#             */
/*   Updated: 2025/05/24 11:35:34 by lebartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hotrace.h"


char *hash_lookup(t_data *data, char *key)
{
	uint32_t	target_hashed_key;
	t_entry		*entry;
	int			index;

	if (!data || !key)
		return (NULL);
	entry->key = key;
	index = get_index(data, entry);
	target_hashed_key = entry->hashed_key;

	if (data->entries[index]->next  == NULL)
		return (data->entries[index]->value);
	// horizontal collision
	entry = data->entries[index];
	while (entry != NULL)
	{
		if (ft_strcmp(entry->hashed_key, target_hashed_key) == 0)
			return (entry->value);
		entry = entry->next;
	}
	return (NULL);
}

// // bo mi par giusto, fatto da copilot
// int is_prime(int n)
// {
// 	if (n <= 1)
// 		return (0);
// 	if (n <= 3)
// 		return (1);
// 	if (n % 2 == 0 || n % 3 == 0)
// 		return (0);
// 	for (int i = 5; i * i <= n; i += 6)
// 	{
// 		if (n % i == 0 || n % (i + 2) == 0)
// 			return (0);
// 	}
// 	return (1);
// }

// int nearest_prime(int n)
// {
// 	int i;

// 	while (i > 0)
// 	{
// 		if (is_prime(n))
// 			return (n);
// 		i--;
// 	}
// }

// // non ho chiaro come gestire nel caso di due collisioni.
// // nel caso utilizzo l'hash del target all'interno di insert_entry doublehashindex(data, target->hashed_key);
// // non serve, forse per la norma...
// // le parole non possono descrivere quanto odi quel ft_atoi.
// int double_hash_index(t_data *data, t_entry entry)
// {
// 	return (ft_atoi(entry.hashed_key) % nearest_prime(MAX_ENTRIES));
// }

// prende una entry e la inserisce nell'array entries
int get_index(t_data *data, t_entry *entry)
{
	entry->hashed_key = MurmurHash2(entry->key, ft_strlen(entry->key), MAX_ENTRIES);
	return (entry->hashed_key % MAX_ENTRIES);
}


// hash a gruppi di 4 byte, ogni 4 byte viene moltiplicato per un numero 'magico'
uint32_t MurmurHash2 ( const void * key, int len, uint32_t seed )
{
  const uint32_t m = 0x5bd1e995;
  const int r = 24;
  uint32_t h = seed ^ len;
  const unsigned char * data = (const unsigned char *)key;

  while(len >= 4)
  {
    uint32_t k = *(uint32_t*)data;

    k *= m;
    k ^= k >> r;
    k *= m;

    h *= m;
    h ^= k;

    data += 4;
    len -= 4;
  }
  if (len == 1);
  else if (len == 3) h ^= data[2] << 16;
  else if (len == 2) h ^= data[1] << 8;


  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  return h;
}

// implementazione piu performante sui sistemi a 64 bit

// bool qhashmurmur3_128(const void *data, size_t nbytes, void *retbuf) {
//     if (data == NULL || nbytes == 0)
//         return false;

//     const uint64_t c1 = 0x87c37b91114253d5ULL;
//     const uint64_t c2 = 0x4cf5ad432745937fULL;

//     const int nblocks = nbytes / 16;
//     const uint64_t *blocks = (const uint64_t *) (data);
//     const uint8_t *tail = (const uint8_t *) (data + (nblocks * 16));

//     uint64_t h1 = 0;
//     uint64_t h2 = 0;

//     int i;
//     uint64_t k1, k2;
//     for (i = 0; i < nblocks; i++) {
//         k1 = blocks[i * 2 + 0];
//         k2 = blocks[i * 2 + 1];

//         k1 *= c1;
//         k1 = (k1 << 31) | (k1 >> (64 - 31));
//         k1 *= c2;
//         h1 ^= k1;

//         h1 = (h1 << 27) | (h1 >> (64 - 27));
//         h1 += h2;
//         h1 = h1 * 5 + 0x52dce729;

//         k2 *= c2;
//         k2 = (k2 << 33) | (k2 >> (64 - 33));
//         k2 *= c1;
//         h2 ^= k2;

//         h2 = (h2 << 31) | (h2 >> (64 - 31));
//         h2 += h1;
//         h2 = h2 * 5 + 0x38495ab5;
//     }

//     k1 = k2 = 0;
//     switch (nbytes & 15) {
//         case 15:
//             k2 ^= (uint64_t)(tail[14]) << 48;
//         case 14:
//             k2 ^= (uint64_t)(tail[13]) << 40;
//         case 13:
//             k2 ^= (uint64_t)(tail[12]) << 32;
//         case 12:
//             k2 ^= (uint64_t)(tail[11]) << 24;
//         case 11:
//             k2 ^= (uint64_t)(tail[10]) << 16;
//         case 10:
//             k2 ^= (uint64_t)(tail[9]) << 8;
//         case 9:
//             k2 ^= (uint64_t)(tail[8]) << 0;
//             k2 *= c2;
//             k2 = (k2 << 33) | (k2 >> (64 - 33));
//             k2 *= c1;
//             h2 ^= k2;

//         case 8:
//             k1 ^= (uint64_t)(tail[7]) << 56;
//         case 7:
//             k1 ^= (uint64_t)(tail[6]) << 48;
//         case 6:
//             k1 ^= (uint64_t)(tail[5]) << 40;
//         case 5:
//             k1 ^= (uint64_t)(tail[4]) << 32;
//         case 4:
//             k1 ^= (uint64_t)(tail[3]) << 24;
//         case 3:
//             k1 ^= (uint64_t)(tail[2]) << 16;
//         case 2:
//             k1 ^= (uint64_t)(tail[1]) << 8;
//         case 1:
//             k1 ^= (uint64_t)(tail[0]) << 0;
//             k1 *= c1;
//             k1 = (k1 << 31) | (k1 >> (64 - 31));
//             k1 *= c2;
//             h1 ^= k1;
//     };

//     //----------
//     // finalization

//     h1 ^= nbytes;
//     h2 ^= nbytes;

//     h1 += h2;
//     h2 += h1;

//     h1 ^= h1 >> 33;
//     h1 *= 0xff51afd7ed558ccdULL;
//     h1 ^= h1 >> 33;
//     h1 *= 0xc4ceb9fe1a85ec53ULL;
//     h1 ^= h1 >> 33;

//     h2 ^= h2 >> 33;
//     h2 *= 0xff51afd7ed558ccdULL;
//     h2 ^= h2 >> 33;
//     h2 *= 0xc4ceb9fe1a85ec53ULL;
//     h2 ^= h2 >> 33;

//     h1 += h2;
//     h2 += h1;

//     ((uint64_t *) retbuf)[0] = h1;
//     ((uint64_t *) retbuf)[1] = h2;

//     return true;
// }