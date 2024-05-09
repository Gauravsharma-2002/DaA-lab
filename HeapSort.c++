#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int N, int i)
{

    int largest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < N && arr[l] > arr[largest])
        largest = l;

    if (r < N && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{

    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i > 0; i--)
    {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void print(int arr[], int N)
{

    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
void takeInput()
{
    int num;
    cout << "size: ";

    cin >> num;

    vector<int> arr;

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
  
    cout << "hello" << endl;


}
int main()
{
    int arr[] = {12, 43, 2, 4, 1, 2};
    int N = sizeof(arr) / sizeof(arr[0]);

    print(arr, N);

    heapSort(arr, N);

    print(arr,N);

    return 0;
}