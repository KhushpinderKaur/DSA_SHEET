#include <iostream>
using namespace std;

// Function to multiply mid N times
double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 0; i <= n; i++) {
        ans = ans * number;
    }
    return ans;
}

// Function to find Nth root using Binary Search
double NthRoot(int N, int M) {
    double low = 1;
    double high = M;
    double eps = 1e-6;

    while((high - low) > eps) {
        double mid = low + (high - low) / 2.0;
        if(multiply(mid, N) > M){
            high = mid;    //don't do mid-1/mid+1 in double
        } else {
            low = mid;
        }
    }
     return low; 
}

int main() {
    int N, M;

    cout << "Enter value of N (root): ";
    cin >> N;
    cout << "Enter value of M (number): ";
    cin >> M;
    double result = NthRoot(N, M);
    cout << "Nth root is: " << result << endl;
    return 0;
}