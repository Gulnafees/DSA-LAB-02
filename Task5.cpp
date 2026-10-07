/*int a=5, b=10; 
	int *pa=&a; //pa and pb are pointer variables of type int. 
	int *pb=&b;
	
	int **ppa=&pa; //ppa and ppb are called double pointers or pointers-to-pointers.
	int **ppb=&pb;

a)	Write code of a function that swaps values of variables a and b. Input to the function should be the address of both the variables.
*/

#include <iostream>
using namespace std;

int swap( int *a, int *b){

    int temp= *a;
    *a=*b;
    *b=temp;
}

int doubleswap( int **a, int **b){
    int temp= **a;
    **a=**b;    
    **b=temp;

}
int main(){

int a=5, b=10; 
cout<<"before swapping: " << "a: " << a << ", b: " << b << endl;
	int *pa=&a; //pa and pb are pointer variables of type int. 
	int *pb=&b;
	
	int **ppa=&pa; //ppa and ppb are called double pointers or pointers-to-pointers.
	int **ppb=&pb;

    // for a requiremnet of swabpping 
swap(pa, pb);    
cout<<"after swapping: " << "a: " << a << ", b: " << b << endl;

//b)	Write code of a function that swaps values of the variables a and b using pointer-to-pointer variables ppa and ppb.

doubleswap(ppa, ppb);

cout<<"after double swapping: " << "a: " << a << ", b: " << b << endl;


}