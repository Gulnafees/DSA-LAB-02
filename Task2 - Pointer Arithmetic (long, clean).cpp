#include <iostream>
using namespace std;

int main()
{
    long a, *pa;

    pa = &a;


    cout << "pa = &a --> pa = " << pa << endl << endl;

    pa = pa + 1;

    cout << "pa = pa + 1 --> pa = " << pa << endl << endl;

    pa = pa + 3;

    cout << "pa = pa + 3 --> pa = " << pa << endl << endl;

    pa = pa - 1;

    cout << "pa = pa - 1 --> pa = " << pa << endl << endl;

    return 0;
}