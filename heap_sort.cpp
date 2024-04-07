#include<iostream>
using namespace std;

void maxHeap(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        // if child bigger than parent
        if (arr[i] > arr[(i - 1) / 2]) {
            int j = i;

            //swap child and parent until parent is smaller
            while (arr[j] > arr[(j - 1) / 2]) {
                swap(arr[j], arr[(j - 1) / 2]);
                j = (j - 1) / 2;
            }
        }
    }
}



void heapMaxSort(int arr[], int n) {
    maxHeap(arr, n);
    
    for (int i = n - 1; i > 0; i--) {
        // swap value of first indexed with last indexed
        swap(arr[0], arr[i]);

        // maintaining heap property after each swapping
        int j = 0, index;

        do {
            index = (2 * j + 1);

            // if left child is smaller than right child point index variable to right child
            if (arr[index] < arr[index + 1] && index < (i - 1))
                index++;

            // if parent is smaller than child then swapping parent with child having higher value
            if (arr[j] < arr[index] && index < i)
                swap(arr[j], arr[index]);

            j = index;
        } while (index < i);
    }
}

void minHeap(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        // if child smaller than parent
        if (arr[i] < arr[(i - 1) / 2]) {
            int j = i;

            // swap child and parent until parent is larger
            while (arr[j] < arr[(j - 1) / 2]) {
                swap(arr[(j - 1) / 2], arr[j]);
                j = (j - 1) / 2;
            }
        }
    }
}

void heapMinSort(int arr[], int n) {
    minHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        int j = 0, index;
        do {
            index = 2 * j + 1;
            if (arr[index] > arr[index + 1] && index < i - 1)
                index++;

            if (arr[j] > arr[index] && index < i)
                swap(arr[j], arr[index]);

            j = index;
        } while (index < i);
    }
}

int main() {
    int arr[] = {100, 200, 105, 117, 109, 210};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Given Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    heapMaxSort(arr, n);

    // print array after sorting 
    cout << "Max Heap Sorted Array: ";
    for (int i = 0; i < n; i++) {

        cout << arr[i] << " ";
    }
    cout << endl;

    heapMinSort(arr, n);

    // print array after sorting 
    cout << "Min Heap Sorted Array: ";
    for (int i = 0; i < n; i++) {

        cout << arr[i] << " ";
    }
    
}
