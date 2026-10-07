#include <iostream>
using namespace std;

int main(){
    int n;

    // --- Read and validate n (1-10) ---
    do{
        cout << "Enter number of students (1-10): ";
        cin >> n;
    } while(n < 1 || n > 10);

    // --- Allocate original block of n marks ---
    int *marks = new int[n];

    for(int i = 0; i < n; i++){
        cout << "Enter mark for student " << i+1 << ": ";
        cin >> *(marks + i);
    }

    // --- Step 1: Allocate second block of (n+1) integers ---
    int *newMarks = new int[n + 1];

    // Copy original n values using pointer notation
    for(int i = 0; i < n; i++){
        *(newMarks + i) = *(marks + i);
    }

    // Read the new mark into the final position
    cout << "Enter mark for new student: ";
    cin >> *(newMarks + n);

    // --- Step 2: Release old block, repoint, update size ---
    delete[] marks;      // release old block
    marks = newMarks;    // original pointer now refers to new block
    n = n + 1;            // update stored size
    newMarks = nullptr;   // optional: avoid an extra alias to the same block

    // Display all values
    cout << "\nUpdated marks: ";
    for(int i = 0; i < n; i++){
        cout << *(marks + i) << " ";
    }
    cout << endl;

    // --- Step 3: Release the final block exactly once ---
    delete[] marks;
    marks = nullptr;

    return 0;
}