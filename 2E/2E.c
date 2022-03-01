#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define randnum(min, max) \
        ((rand() % (int)(((max) + 1) - (min))) + (min))
		
void osszeg(int *szam, int x);
void minimum(int *szam, int x);
void maximum(int *szam, int x);

int main()
{
	//1.feladat
	int i = 0;
	int n = 0;
	int t[n];
	
	printf("Hany darab erteket szeretne a tombe? \ndb = ");
	scanf("%d", &n);
	printf("\nOn egy %d db ertekekkel rendelkezo tombot akar hasznalni.", n);
	
	for(i = 0; i < n; i++)
	{
		printf("\nAdja meg az %d erteket : ", i);
		scanf("%d", &t[i]);
	}
	
	printf("Az on tombjenek ertekei : ");
	for(i = 0; i < n; i++)
	{
		printf(" %d", t[i]);
	}
	
	osszeg(t, n);
	minimum(t, n);
	maximum(t, n);
}

void osszeg(int *szam, int x){
	int ossz = 0;
   for(int i = 0; i < x; i++)
   {
	  ossz = ossz + szam[i]; 
   }
   printf("\nA random ertekek osszege : %d ", ossz);
} 

void minimum(int *szam, int x) {
	int min = szam[0];
	for(int i = 1; i < x; i++) 
    {
		if(min > szam[i])
		{
			min = szam[i];
		}
	}
	printf("\nA minimum ertek a tombben : %d", min);
}

void maximum(int *szam, int x) {
	int max = szam[0];
	for(int i = 1; i < x; i++) 
    {
		if(max < szam[i])
		{
			max = szam[i];
		}
	}
	printf("\nA maximum ertek a tombben : %d", max);
}

