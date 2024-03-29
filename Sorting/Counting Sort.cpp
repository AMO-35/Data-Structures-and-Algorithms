#include <bits/stdc++.h>
using namespace std;

//Time Complexity - O(max(A[i], n))
void countSort(int arr[], int n) {
    int k = arr[0];

    for (int i = 0; i < n; ++i)
        k = max(k, arr[i]);

    int count[10] = {0};

    for (int i = 0; i < n; ++i)
        count[arr[i]]++;

    for (int i = 1; i <= k; ++i)
        count[i] += count[i-1];

    int output[n];

    for (int i = n-1; i >= 0; --i)
        output[--count[arr[i]]] = arr[i];

    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

void run_case() {
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    countSort(arr, 9);

    for (int i = 0; i < 9; ++i)
        cout << arr[i] << ' ';

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    
    int tests = 1;

    while (tests-- > 0)
        run_case();

    return 0;
}
