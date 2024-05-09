#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    vector<int> arr = {24, -8, 25, -6, -46, 23, 12, -12, -10, 2}; // Example input array
    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    insertionSort(arr); // insertionSort function call with input argument as Array arr
    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
