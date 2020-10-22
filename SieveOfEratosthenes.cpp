/* This code illustrates how we can find all the prime numbers from 1 to N with a time complexity of O(Nlog(logN)) which is less than 
	Naive approach with a time complexity of O(N^2) */

#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

int main() {
	/* first, we consider the end of a range, example, here we consider 10, so we find all the prime numbers between 1 to 10. */
    int A=10;
	
	/* next, we create an array of size A+1. The reason being, we need to find all the primes from 1 till A.
		Then, we initialize it with 0. */
    int arr[A+1]={0};
    
	/* We change the value of index 0 and 1 to 1 because they are not primes */
    arr[0]=arr[1]=1;
    
	/* Finally we start looping from 1 to square root of the number. The reason for choosing square root is because:
		for example, if there is a number 100, then it's root will be 10. So if, there's any number greater than 10 
		then the other factor must be less than 10, like 2*50 = 50*2  */
    for(int i=2; i<=floor(sqrt(A)); i++){
		
		/* We only consider the multiples of the current value of i, like if i=2, then multiples will be 4, 6, 8, 10, etc.
			Since, the multiples of the current number will always be non-prime, we make their respective index value as 1 */
        for(int j=2; i*j<=A; j++){
            arr[i*j]=1;
        }
    }
    
	/* Finally we print only those indexes whose value is 0 */
    for(int i=0; i<=A; i++){
        if(!arr[i])
            cout<<i<<" ";
    }
}