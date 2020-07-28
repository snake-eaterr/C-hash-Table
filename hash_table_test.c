#include <stdio.h>
#include "hash_table.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>


const char alphabet[] = "abcdefghijklmnopqrstuvwxyz0123456789";

int intN(int n) { return rand() % n; }


char *randomString(int len) {
  char *rstr = malloc((len + 1) * sizeof(char));
  int i;
  for (i = 0; i < len; i++) {
    rstr[i] = alphabet[intN(strlen(alphabet))];
  }
  rstr[len] = '\0';
  return rstr;
}

int main()
{
    srand(time(NULL));
    ht_hash_table *hashTable = ht_new();
    printf("---------------%d\n", hashTable->size );
    
    char *s[50];
    //char *f[500];
   

    for (int i = 0; i < 50; i++)
    {
        s[i] = randomString(10);
        ht_insert(hashTable, s[i], randomString(10));
    }


    char *t = s[20];
    clock_t tic = clock();
    char *f = ht_search(hashTable, t);
    clock_t toc = clock();
    printf("Elapsed: %f seconds\n", (double)(tic - toc) / CLOCKS_PER_SEC );

   
}