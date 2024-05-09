
// Binary Search recurssive utilising D&C

#include <iostream>
#include <vector>

using namespace std;

// Function to perform binary search recursively
int binary_search_recursive(vector<int> &arr, int target, int left, int right)
{
    if (left > right)
    {
        // Base case: element not found
        return -1;
    }
    int mid = (left + right) / 2;
    // when element is at mid
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    { // element is at right half
        return binary_search_recursive(arr, target, mid + 1, right);
    }
    else
    { // target is at left half
        return binary_search_recursive(arr, target, left, mid - 1);
    }
}

// Function to perform binary search
int binary_search(vector<int> &arr, int target)
{
    return binary_search_recursive(arr, target, 0, arr.size() - 1);
}

int main()
{
    vector<int> arr = {1,5,12,13,25,25,26,28,29,35,37,49,50,55,65,67};
    int target ;
    cin>>target;
    int result_index = binary_search(arr, target);
    if (result_index != -1)
    {
        cout << "Element " << target << " found at index " << result_index << "." << endl;
    }
    else
    {
        cout << "Element " << target << " not found." << endl;
    }
    return 0;
}