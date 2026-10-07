#include <iostream>
using namespace std;

int main(){
    int n = 3;
    int* values = new int[n];

    for(int i = 0; i < n; i++)       // fixed bound
        cin >> values[i];

    cout << "Values: ";
    for(int i = 0; i < n; i++)
        cout << values[i] << " ";
    cout << endl;

    delete[] values;    // matches new[]
    values = nullptr;   // avoid dangling pointer
    return 0;
}