#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
// Function to heapify a subtree rooted with node i 
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }}
//  heap sort function
void heapSort(vector<int> &arr)
{
    int n = arr.size();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {  // Move current root to end
        swap(arr[0], arr[i]);
        //  max heapify on reduced heap
        heapify(arr, i, 0);
    }
}
// Function to generate random numbers and fill the array
void generateRandomNumbers(vector<int> &arr, int n)
{
    srand(time(0)); // Seeding random  generator
    for (int i = 0; i < n; ++i)
    {
        arr.push_back(rand() % 1000); // Generate random numbers between 0 and 999
    }
}

int main()
{
    vector<long long int> n_values = {10, 100, 1000, 10000, 100000, 1000000,10000000}; // Different values of n
    for (int n : n_values)
    {
        vector<int> arr;
        generateRandomNumbers(arr, n); // Generate random numbers for the array

        // Measure the time required for sorting
        auto start = high_resolution_clock::now();
        heapSort(arr); // calling sort function with input argument as arr randomly generated
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Time taken to sort " << n << " elements: " << duration.count() << " milliseconds" << endl;
    }

    return 0;
}
