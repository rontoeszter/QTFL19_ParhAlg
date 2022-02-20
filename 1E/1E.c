#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define randnum(min, max) \
        ((rand() % (int)(((max) + 1) - (min))) + (min))
		
void prim();

int main()
{
	
//2.feladat
for(int i = 1; i < 8; ++i) {
printf(" %9d", i);
}

printf("\n");

//3.feladat
printf("\nJo Szerencset!");
sleep (2);
printf("\nTisztelet a Gepesznek!\n");

printf("\n");

//4.feladat
srand(time(NULL));
printf("%d\n", randnum(500, 1000));
printf("%f\n", (float)randnum(500, 1000));

printf("\n");

//5.feladat
int a = 0;
int b = 0;
do
{
printf("Add meg az a erteket: ");
scanf("%d", &a);  
printf("Add meg a b erteket: ");
scanf("%d", &b);
//printf("Az altalad meg adott ertekek = %d, %d \n", &a, &b);
if(a > b)
{
printf("Az a ertekenek kisebbnek kell lennie mint a b ertekenek!\n");
}
}while(a > b);
srand(time(NULL));
printf("A random ertek a ket ertek kozott: %d\n", randnum(a, b));

printf("\n");

//6.feladat
clock_t begin, end;
double time_spent;

srand(time(NULL));
int x = randnum(0, 100);
int y = randnum(0, 100);
int e = 0;

printf("%d + %d = ?", x, y);
begin = clock();
time_spent = (double)begin / CLOCKS_PER_SEC;

for(time_spent=0.0; time_spent<62000.0; time_spent++)
{
	printf("\nAdja meg az eredmenyt: ");
	scanf("%d", &e);
	
	if(x+y == e)
	{
		printf("Helyes eredmenyt adott meg.\n"); 
		break;
	}
    else
	{
		printf("Helytelen az on altal meg adott ertek.\n");
		break;
	}
}
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("A szamitas %lf mp-ig tartott.", time_spent);

printf("\n");

//7.feladat
prim();


printf("\n");
return 0;
}



//7.feladat
void prim() {
	clock_t start, fin;
	double t_spent;
	int db = 0, z = 0, flag;
	int r = 1000;
	double ido[20];
	
	/*srand(time(NULL));
	int n = randnum(1, 20000);*/
	int n = 10;
	
	start = clock();
	t_spent = (double)start / CLOCKS_PER_SEC;
for(t_spent=0.0; t_spent<62000.0; t_spent++)
{
	for(int i = 2; i <= n; i++) {
		flag = 0;
		for(int j = 2; j <= i / 2; j++){
			if(i % j == 0) {
				flag = 1;
				break;
			}
		}
		if(flag == 0 && i >= 2) {
			db++;
		}
		
		if(i == r) {
			printf("Itt i = 1000");
			fin = clock();
			t_spent = (double)(fin - start) / CLOCKS_PER_SEC;
			ido[z] = t_spent;
			z++;
			r = r + 1000;
		}
	}
	break;
}
	
	printf("\n1 es %d kozott %d db primszam talalhato.", n, db);
	printf("\nMikor az ertek egyenlo volt 1000-el akkor az ido %lf mp-nel jart. ", t_spent);
}
