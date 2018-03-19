#include "fibonacci.h"
#include "util.h"

long int *fibonacci( long int *first, long int *last, long int value, long int *counter )
{
	long int size = (last - first);
/*	vf[] = Fibseq(size);
	long int Fibn
	
	for (auto i(0); i <= size; i++)
	{
		if( vf[i] >= size)
		{
			Fibn = vf[i];
			break;
		}
		else
		{
			continue;
		}	
	}
*/
	long int fib2 = 0;
	long int fib1 = 1;
	long int fibM = fib2 + fib1;

	while(fibM < size)
	{
		fib2 = fib1;
		fib1 = fibM;
		fibM = fib2 + fib1;	
	}

	long int offset = -1;

	while(fibM > 1)
	{
		long int i = min(offset + fib2, size - 1); // checks if fib2 is a valid location

		if(*(first + i) > value)
		{
			fiM = fib1;
			fib1 = fib2;
			fib2 = fibM - fib1;
			offset = i;
		}

		else if(*(first + i) > value)
		{
			fibM = fib2;
			fib1 = fib1 - fib2;
			fib2 = fibM - fib1;
		}

		else return &i;
			
	}
	
	if(fib1 and *(first + offset + 1) == value) 
	{
		return offset + 1;	
	}
	
	return -1 // Element not found	
		
}
