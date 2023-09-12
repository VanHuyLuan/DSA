#include <iostream>
#include <vector>
using namespace std;

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void radixSort(int arr[], int n) {
    int max = findMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        vector<int> bucket[10];

        for (int i = 0; i < n; i++) {
            int index = (arr[i] / exp) % 10;
            bucket[index].push_back(arr[i]);
        }

        int j = 0;
        for (int i = 0; i < 10; i++) {
            for (int num : bucket[i]) {
                arr[j] = num;
                j++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n ;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n ; i++)
    {
        cin >> arr[i];
    }

    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    radixSort(arr, n);

    cout << "\nMang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

