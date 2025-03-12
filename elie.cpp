#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

// Function to calculate factorial
unsigned long long factorial(int num) {
    if (num == 0 || num == 1)
        return 1;
    return num * factorial(num - 1);
}

// Function to calculate permutation
unsigned long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate combination
unsigned long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, r;

    // Input n and r with error checking
    do {
        cout << "\nEnter n (positive integer): ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            cout << "\nInvalid input. Please enter a positive integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (n <= 0);

    do {
        cout << "\nEnter r (positive integer, r <= n): ";
        cin >> r;
        if (cin.fail() || r <= 0 || r > n) {
            cout << "\nInvalid input. Please enter a positive integer not greater than n.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (r <= 0 || r > n);

    // Print table header
    cout << "\n" << setw(5) << "n" << setw(5) << "r" << setw(15) << "nPr" << setw(15) << "nCr" << endl;
    cout << string(40, '-') << endl;

    // Calculate and print permutations and combinations
    for (int i = r; i <= n; ++i) {
        unsigned long long nPr = permutation(n, i);
        unsigned long long nCr = combination(n, i);

        cout << setw(5) << n << setw(5) << i << setw(15) << nPr << setw(15) << nCr << endl;
    }
        cout << string(40, '-') << endl;
    return 0;
}