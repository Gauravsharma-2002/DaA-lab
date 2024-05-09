#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &arr)
{  int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    { // Find the minimum
        int min_index = i;
        for (int j = i + 1; j < n; ++j){ 
            if (arr[j] < arr[min_index])
            {  min_index = j; }}
        // Swap  minimum element with first element
        if (min_index != i)
        { swap(arr[i], arr[min_index]); }}}

int main()
{
    vector<int> arr =  {24, -8, 25, -6, -46, 23, 12, -12, -10, 2}; // Example input array
    cout << "Original array: ";
    for (int num : arr)
    {cout << num << " ";}
    cout << endl;
    selectionSort(arr); // selectionSort function call with input argument as arr
    cout << "Sorted array: ";
    for (int num : arr){cout << num << " ";}
    cout << endl; return 0; }
