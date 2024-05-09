#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int begin, int mid, int end)
{
    vector<int> temp;
    int left = begin;
    int right = mid + 1;
    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }
    while (right <= end)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = begin; i <= end; i++)
    {
        arr[i] = temp[i - begin];
    }
}
void mergeSort(vector<int> &arr, int begin, int end)
{
    if (begin >= end)
        return;

    int mid = (begin+end)/2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}
void print(vector<int> arr)
{
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> arr = {4, 3, 2, 87, 43, 23, 64, 1, 23};
    int size = arr.size();
    print(arr);
    
    mergeSort(arr, 0, 8);
    cout<<"after sorting" <<endl;
    print(arr);

    return 0;
}