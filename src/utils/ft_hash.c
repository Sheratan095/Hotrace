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

#include "../../includes/Hotrace.h"

// hash a gruppi di 4 byte, ogni 4 byte viene moltiplicato per un numero 'magico'


// prende una entry e la inserisce nell'array entries
void get_index(t_data *data, t_entry *entry)
{
	uint32_t hash;
	hash = MurmurHash2(entry->key, ft_strlen(entry->key), 0);
}



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