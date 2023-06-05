#include <iostream>

using namespace std;

long arrayManipulation(int n, int m, int queries[][3]) {
    long* arr = new long[n + 2](); // Create a dynamic array initialized with zeros

    for (int i = 0; i < m; i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        arr[a] += k;
        arr[b + 1] -= k;
    }

    long maxVal = 0;
    long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += arr[i];
        maxVal = max(maxVal, sum);
    }

    delete[] arr; // Deallocate the dynamically allocated array

    return maxVal;
}

int main() {
    int n, m;
    cin >> n >> m;

    int queries[m][3];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }
    }

    long result = arrayManipulation(n, m, queries);
    cout << result << endl;

    return 0;
}
