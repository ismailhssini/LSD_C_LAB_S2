#include <stdio.h>
#include <stdlib.h>

int recursive_fibo(int n)
{
	if (n==0)
		return 0;
	if (n==1)
		return  1;
	else
		return recursive_fibo(n-1)+recursive_fibo(n-2);
}

int iterative_fibo(int n)
{
	int nbr1=0,nbr2=1,suivant;
	if (n==0)
		return 0;
	if (n==1)
		return  1;
	for (int i = 2; i < n+1; i++)
  	{
      		suivant = nbr1 + nbr2;
      		nbr1 = nbr2;
      		nbr2 = suivant;
    }	
 	return suivant;
}
int maxTableau(int n)
{
	int T[n];
	for (int i=0;i<n;i++)
	{
		T[i]=rand()%20;
	}
	for (int i=0;i<n;i++)
	{
		printf("%d  ",T[i]);
	}
}
int main()
{
	printf("%d",maxTableau(6));
	return 0;
} 
