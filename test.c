#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	char *key;
	char *value;
} ht_item;

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

ht_item* get_item(const char *x, const char *y)
{
	ht_item *item = malloc(sizeof(ht_item));
	item->key = strdup(x);
	item->value = strdup(y);
	return item;
}
char* search(ht_item **array, const char *key)
{
	for (int i = 0; i < 500; i++)
	{
		if(strcmp(array[i]->key, key) == 0)
			return array[i]->value;
	}
	return NULL;
}

int main()
{

	srand(time(NULL));
	ht_item **item_array = calloc((size_t) 50, sizeof(ht_item*));
	char *s[50];
	for (int i = 0; i < 50; i++)
	{
		s[i] = randomString(10);
		item_array[i] = get_item(s[i], randomString(10));
	}
	char *t = s[20];
	clock_t tic = clock();
	char *x = search(item_array, t);
	clock_t toc = clock();
	printf("Elapsed: %f seconds\n", (double)(tic - toc) / CLOCKS_PER_SEC );
	if(x != NULL)
		printf("found: %s\n", x);
	else
		printf("not found\n");
}