#include <iostream>
using namespace std;

int main(){
    int rows, cols;

    // --- Step 1: Read and validate rows and cols ---
    do{
        cout << "Enter number of students (rows): ";
        cin >> rows;
    } while(rows <= 0);

    do{
        cout << "Enter number of subjects (cols): ";
        cin >> cols;
    } while(cols <= 0);

    // --- Step 2: Allocate row-pointer array, then allocate each row ---
    int **marks = new int*[rows];
    for(int r = 0; r < rows; r++){
        marks[r] = new int[cols];
    }

    // --- Step 3: Read marks (using pointer notation for this loop) ---
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            cout << "Student " << r+1 << ", Subject " << c+1 << ": ";
            cin >> *(*(marks + r) + c);   // equivalent to marks[r][c]
        }
    }

    // --- Display the matrix ---
    cout << "\nMarks Matrix:\n";
    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            cout << marks[r][c] << " ";
        }
        cout << endl;
    }

    // --- Step 4: Calculate totals and find the top student ---
    int bestTotal = 0, bestStudent = 1;

    for(int r = 0; r < rows; r++){
        int total = 0;
        for(int c = 0; c < cols; c++){
            total += marks[r][c];
        }
        cout << "Student " << r+1 << " total: " << total << endl;

        if(r == 0){
            bestTotal = total;      // first student's total sets initial best
            bestStudent = 1;
        }
        else if(total > bestTotal){ // strictly greater — ties keep the earlier student
            bestTotal = total;
            bestStudent = r+1;
        }
    }

    cout << "\nTop student: " << bestStudent 
         << " with total: " << bestTotal << endl;

    // --- Step 5: Deallocate memory ---
    for(int r = 0; r < rows; r++){
        delete[] marks[r];   // delete each row
    }
    delete[] marks;          // delete the row-pointer array
    marks = nullptr;         // avoid dangling pointer

    return 0;
}