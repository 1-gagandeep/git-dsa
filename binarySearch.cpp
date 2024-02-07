#include<iostream>
using namespace std;

int main() {

    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter elements of array: ";
    for(int i = 0; i < size; i++)
    cin >> arr[i];

    int item;
    cout << "Enter item for search: ";
    cin >> item;

    int first = 0;
    int last = size-1;
    int mid = (first+last)/2;

    while(first <= last) {
        if(arr[mid] == item) {
            cout << item << " Element found at location " << mid;
            break;
        }

        if(arr[mid] > item) {
            last = mid - 1;
        }

        if(arr[mid] < item) {
            first = mid + 1;
        }

        mid = (first + last)/2;
    }
    delete[] arr;
}