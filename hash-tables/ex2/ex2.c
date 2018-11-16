#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"


int main(void)
{
  Ticket **tickets = malloc(3 * sizeof(Ticket *));

  Ticket *ticket_1 = malloc(sizeof(Ticket));
  ticket_1->source = "NONE";
  ticket_1->destination = "PDX";
  tickets[0] = ticket_1;

  Ticket *ticket_2 = malloc(sizeof(Ticket));
  ticket_2->source = "PDX";
  ticket_2->destination = "DCA";
  tickets[1] = ticket_2;

  Ticket *ticket_3 = malloc(sizeof(Ticket));
  ticket_3->source = "DCA";
  ticket_3->destination = "NONE";
  tickets[2] = ticket_3;

  // char *expected[] = { "PDX", "DCA", "NONE" };
  print_route(reconstruct_trip(tickets, 3), 3);

  return 0;
}

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));

  // YOUR CODE HERE
  //find the starting location and the end location.
  //return both start and destination but also the stops along the way
  //loop through the length
  //insert the source ticket and the destination tickwet into the hash table
  for(int i = 0; i < length; i++){
    hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
  }
  
  route[0] = hash_table_retrieve(hash, "NONE");

  //loop through length again to create the route.
  for(int i = 1; i < length; i++){
    route[i] = hash_table_retrieve(hash, route[i - 1]);
  }
  destroy_hash_table(hash);
  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}