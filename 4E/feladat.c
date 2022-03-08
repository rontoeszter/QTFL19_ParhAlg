#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define randnum(min, max) \
        ((rand() % (int)(((max) + 1) - (min))) + (min))

int main() {

	int n = 0;
	int t[n];
	int i = 0;
	
	
	printf("\nMennyi elembol alljon a tomb? ... ");
	scanf("%d", &n);
	
	srand(time(NULL));
	for(i = 0; i < n; i++) 
	{	
		t[i] = randnum(0, 10);
	}
	
	printf("\nA tomb elemei: ");
	for(i = 0; i < n; i++) 
	{
		printf("%d  ", t[i]);
	}
	
	int szorzat = t[0];
	for(i = 1; i < n; i++) 
	{
		szorzat = szorzat * t[i]; 
	}
	printf("\nA tomb elemeinek szorzata: %d\n", szorzat);
	
	
}