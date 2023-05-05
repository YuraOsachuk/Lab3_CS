#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < 100000; i++) {
        int arr[120];
        for (int j = 0; j < 120; j++) {
            arr[j] = rand() % 120 + 1;
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        for (int j = 0; j < 120; j++) {
            selectionSort(arr, n);
        }
    }
    cout << "DONE" << endl;
    return 0;
}