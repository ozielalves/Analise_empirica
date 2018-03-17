#include "ternary.h"

long int *i_ternary( long int *first, long int *last, long int value, long int *counter )
{
	long int *last_backup = last;
	
	while(first != last)
	{
		(*counter) += 1;
		long int *left = first + ( first - last )/(long int)3;
		long int *right = left + ( first - last )/(long int)3;

		//for the left pointer
		if(*left == value)
		{
			return left;
		}
		else // if(*left != value)
		{
			if(*left > value) // value < *last
			{
				last = left - 1; 
			}
			else if(*left < value)
			{
				first = left + 1;
			}

			// for the right pointer
			else if(*right == value)
			{
				return right;
			}
			else if(*right != value)
			{
				if(*right > value)
				{
					last = right - 1;
				}
				else if(*right < value) 
				{
					first = right + 1;	
				}
			}
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
	{ //*left is the value
		return left; 	
	}
	else
	{ //if *left != value 
		if(*left > value)
		{
			last = left - 1;
				return r_ternary( first, last, value, counter );
		}
		if(*left < value)
		{ //if *left < value
			first = left + 1;
				return r_ternary( first, last, value, counter );
		}
	//for the right pointer
	if(*right == value)
	{ //*right is the value
		return right;
	}
	else if(*right !=value)
	{ //if *right != value
		if(*right > value)
		{ // value < *right
			last = right;
				return r_ternary( first, last, value, counter );
		}
		else
		{ //if value > *right
			first = right;
				return r_ternary( first, last, value, counter );
			}
	}
	}
	return last_backup;	
}

