#include "header.h"

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
