#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);

  // YOUR CODE HERE 
  //weights need to add up to the limit
  //length is the amount of items needed to create the limit sum.
  //loop through twice to find the indices of the items 
  //a set of if statements the determine if the weights add up to the limit.
  //return two indices
  LinkedPair *index_1;
  LinkedPair *index_2;
  for(int i = 0; i < ht->storage; i++){
    for(int j = 0; j < ht->storage; j++){
      int index_1 = ht->storage[i];
      int index_2 = ht->storage[j];
      if(index_1 + index_2 > limit || index_1 + index_2 < limit){
        break;
      } else if( index_1 + index_2 == limit){
        return index_1, index_2; 
      }
    }
  }
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}