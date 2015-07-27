
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
void main()
{
    int  i=0, n=0;

    int limit = aski("Até quando, José?");
    
    int * vet = vet_of_ints(limit);
    
    for (i=2; i<limit; i++) 
    {
        *(vet+i)=1;
    }  
    n=2;
    
    while (n<limit)
    { 
        i = n;
        while (i<limit)
        {
            if (i!=n)
            {
                *(vet+i)=0;
            }
            i+=n;
        }
        for (n++; n<limit; n++)
        {
            if (*(vet+n)==1)
            {
                break;
            }
        }
        
    }
    
    for (i=0; i<limit; i++)
    {
        if (*(vet+i)==1)
        {
            printf("%i ", i);
        }
    }  
}