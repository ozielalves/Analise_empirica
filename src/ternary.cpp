#include "ternary.h"

long int *i_ternary( long int *first, long int *last, long int value, long int *counter )
{
	long int *last_backup = last;
	
	while(first != last)
	{
		(*counter) += 1;
		long int *left = first + ( first - last )/(long int)3;
		long int *right = left + ( first - last )/(long int)3;

		if(value >= *first and value < *left)
		{
			last = left - 1;	
		}
		else if(value == *left)
		{
			return left;
		}
		else if(value > *left and value < *right)
		{
			first = left + 1;
			last = right - 1;	
		}
		else if(value == *right)
		{
			return right;	
		}
		else if(value > *right and value < *last)
		{
			first = right + 1;	
		}
	}

	(*counter) += 1;
	return last_backup;	
}

long int *r_ternary( long int *first, long int *last, long int value, long int *counter )
{
	(*counter) ++;
	if(first == last)
	{
		return last;
	}
	
	long int *last_backup = last;
	long int *left = first + ( first - last )/(long int)3;
	long int *right = left + ( first - last )/(long int)3;
	
	//for the left pointer
	if(*left == value)
	{
		return left; 	
	}
	//for the right pointer
	else if(*right == value)
	{
		return right;	
	}
	else if(value >= *first and value < *left)
	{
		last = left - 1; // left was already tested before
		return r_ternary( first, last, value, counter );	
	}
	else if(value > *left and x < *right)
	{
		first = left + 1;
		last = right - 1;
		return r_ternary( first, last, value, counter );	
	}
	else if(value > *right and value < *last)
	{
		first = right + 1;
		return r_ternary( first, last, value, counter );	
	}
	return last_backup;	
}

