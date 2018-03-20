#include "fibonacci.h"
#include "util.h"

long int *fibonacci( long int *first, long int *last, long int value, long int *counter )
{
	long int size = (last - first);
	long int *last_backup = last;
	long int fib2 = 0;
	long int fib1 = 1;
	long int fibM = fib2 + fib1;

	while((fib2 + fib1) < (last - first)) {
		fib2 = fib1;
		fib1 = fibM;
		fibM = fib2 + fib1;	
	}

	long int offset = -1;

	while(fibM > 1) {
		(*counter)++;

		long int i = min(fib2 - 1, size - 1); // checks if fib2 is a valid location

		if(*(first + i) < value) {
			fibM = fib1;
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

		else {
			return first + i;
		}
	}

	if(fib1 and *(first + offset + 1) == value) {
		return (first + offset + 1);	
	}
	
	return last_backup; // Element not found	
}
