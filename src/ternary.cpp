#include "ternary.h"
#include <iostream>

long int *i_ternary( long int *first, long int *last, long int value, long int *counter )
{
	long int *last_backup = last;
	long int *left;
	long int *right;

	while(first < last)
	{
		*counter += 1;
		left = first + ( last - first )/(long int)3;
		right = left + ( last - first )/(long int)3;

		if( /* value >= *first and */ value < *left)
		{
			*counter += 1;
			last = left - 1;	
		}
		else if(value == *left)
		{
			*counter += 2;
			return left;
		}
		else if(value > *left and value < *right)
		{
			*counter += 4;
			first = left + 1;
			last = right;	
		}
		else if(value == *right)
		{
			*counter += 5;
			return right;	
		}
		else
		{
			*counter += 5;
			first = right + 1;	
		}
	
	}
	return last_backup;	
}

long int *r_ternary( long int *first, long int *last, long int value, long int *counter )
{
	if(first == last){
		*counter += 1;
		return last;
	}

	
	long int *last_backup = last;
	long int *left = first + ( last - first )/(long int)3;
	long int *right = left + ( last - first )/(long int)3;
	
	//for the left pointer
	if(*left == value)
	{
		*counter += 2;
		return left; 	
	}
	//for the right pointer
	else if(*right == value)
	{
		*counter += 3;
		return right;	
	}
	else if(value >= *first and value < *left)
	{
		*counter += 5;
		last = left - 1; // left was already tested before
		return r_ternary( first, last, value, counter );	
	}
	else if(value > *left and value < *right)
	{
		*counter += 7;
		first = left + 1;
		last = right - 1;
		return r_ternary( first, last, value, counter );	
	}
	else
	{
		*counter += 7;
		first = right + 1;
		return r_ternary( first, last, value, counter );	
	}
	return last_backup;	
}

