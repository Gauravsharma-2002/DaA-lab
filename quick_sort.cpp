#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono; // for time consumption
// partition function
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; //  last element as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
// Recursive function to perform quick sort
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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
    vector<long long int> n_values = {10, 100, 1000, 10000, 100000, 1000000}; // Different values of n
    for (int n : n_values)
    {
        vector<int> arr;
        generateRandomNumbers(arr, n); // Generate random numbers for the array

        // Measure the time required for sorting
        auto start = high_resolution_clock::now();
        quickSort(arr, 0, n - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Time taken to sort " << n << " elements: " << duration.count() << " milliseconds" << endl;
    }
    return 0;
}
