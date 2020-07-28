#include <stdio.h>
typedef struct 
{
	int x;
	int y;
} peef;
///////
int main()
{
	peef pe = {5, 4};
	printf("%d, %d\n", pe.x, pe.y);
}
