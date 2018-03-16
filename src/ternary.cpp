#include "ternary.h"

long int *r_ternary( long int *first, long int *last, long int value, long int *counter )
{
	(*counter) ++;
	if(first == last){
		return last;
	}
	
	long int *last_backup = last;
	long int *left = first + ( first - last )/(long int)3;
	long int *right = left + ( first - last )/(long int)3;
	
	//for the left pointer
	if(*left == value){ //*left is the value
		return left; 	
	}else{ //if *left != value 
		if(*left > value){
			last = left;
				return r_ternary( first, last, value, counter );
		}else{ //if *left < value
			first = left + 1;
				return r_ternary( first, last, value, counter );
		}

	//for the right pointer
	if(*right == value){ //*right is the value
		return right;
	}else{ //if *right != value
		if(*right > value){ // value < *right
			last = right;
				return r_ternary( first, last, value, counter );
		}else{ //if value > *right
			first = right;
				return r_ternary( first, last, value, counter );
			}
	}
	return last_backup;	
}

