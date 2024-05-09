#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
// Merge sorted subarrays
void merge(vector<int> &arr, int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;    
    vector<int> L(n1), R(n2);//  temporary arrays
    for (int i = 0; i < n1; ++i) // Copy data to temporary arrays 
    { L[i] = arr[low + i]; }
    for (int j = 0; j < n2; ++j)
    {R[j] = arr[mid + 1 + j]; }
    int i = 0, j = 0, k = low; // Merge the temporary arrays back into arr[low..high]
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {arr[k] = L[i];  ++i;}
        else
        { arr[k] = R[j];++j; }
        ++k; }
    // Copy the remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Merge sort function
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2; // Calculate mid index

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

// Function to generate random numbers and fill the array
void generateRandomNumbers(vector<int> &arr, int n)
{
    srand(time(0)); // Seed the random number generator
    for (int i = 0; i < n; ++i)
    {
        arr.push_back(rand() % 1000); // Generate random numbers between 0 and 999
    }
}

int main()
{
    vector<int> n_values = {10, 100, 1000, 10000, 100000, 1000000,10000000}; // Different values of n
    for (int n : n_values)
    {
        vector<int> arr;
        generateRandomNumbers(arr, n); // Generate random numbers for the array

        // Measure the time required for sorting
        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Time taken to sort " << n << " elements: " << duration.count() << " milliseconds" << endl;
    }

    return 0;
}
