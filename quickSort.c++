#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{

    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] < pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicSort(vector<int> &arr, int begin, int end)
{
    if (begin < end)
    {
        int p = partition(arr, begin, end);

        quicSort(arr, begin, p - 1);
        quicSort(arr, p + 1, end);
    }
}
void prit(vector<int> arr){
    int size = arr.size();
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{

    return 0;
}