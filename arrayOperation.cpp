#include <iostream>
using namespace std;
// new comment
class arrayOperation
{
public:
    void create(int *arr, int size)
    {

        cout << "Array created!";
    }

    void traverse(int *arr, int size)
    {

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void search(int *arr, int size)
    {

        int key;
        cout << "Enter key to search in array: ";
        cin >> key;

        int flag = 1;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == key)
            {
                cout << "Element is present";
                flag = 0;
                break;
            }
        }

        if (flag != 0)
            cout << "Element is absent";
    }

    void insert(int *arr, int size)
    {
        int position, value;

        cout << "Enter location: ";
        cin >> position;

        cout << "Enter value: ";
        cin >> value;

        for (int i = size - 1; i >= position; i--)
            arr[i + 1] = arr[i];
        arr[position] = value;

        cout << "Resultant array" << endl;
        for (int i = 0; i < size + 1; i++)

            cout << arr[i] << " ";
    }

    void sort(int *arr, int size)
    {
        int i, j, temp;

        for (i = 0; i < size - 1; i++)
        {
            for (j = 0; j < size - i - 1; j++)
            {

                if (arr[j] > arr[j + 1])
                {

                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        cout << "Array after sorting: ";
        for (i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    void deleteOp(int *arr, int size)
    {
        int item, i, pos = -1;

        cout << "Enter item to delete: ";
        cin >> item;

        for (i = 0; i < size; i++)
        {
            if (arr[i] == item)
            {
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                pos = i;
                size--;
                break;
            }
        }

        if (pos == -1)
        {
            cout << "Item is not present";
        }

        else
        {
            cout << "New array: ";
            for (i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{
    cout << "Choose an operation: 1) For Create 2) For Traverse 3) For Search 4) For Insert 5) For Sort 6) For Delete 7) For Exit." << endl;
    int operation;
    cin >> operation;

    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    arrayOperation ap;

    switch (operation)
    {
    case 1:
        ap.create(arr, size);

        break;

    case 2:
        ap.traverse(arr, size);

        break;

    case 3:
        ap.search(arr, size);

        break;

    case 4:
        ap.insert(arr, size);

        break;

    case 5:
        ap.sort(arr, size);

        break;

    case 6:
        ap.deleteOp(arr, size);

        break;

    default:
        cout << "Invalid";
    }
    delete[] arr;
}