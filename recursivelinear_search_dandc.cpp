#include <iostream>
#include <vector>

using namespace std;

// Recursive linear search function
int search(const vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; //  not found
    }
    if (arr[left] == target) {
        return left; //  found at left index
    }
    if (arr[right] == target) {
        return right; // found at right index
    }
    return search(arr, target, left + 1, right - 1);
}

int main() {
    // Example array 
    vector<int> arr = {1, 13, 15, 17, 19, 121, 123, 125, 127, 129};
    int target ;
    cin>>target;

    //  recursive linear search call
    int result_idx = search(arr, target, 0, arr.size() - 1);
    if (result_idx != -1) {
        cout << "Element " << target << " found at index " << result_idx << "." << endl;
    } else {
        cout << "Element " << target << " not found." << endl;
    }

    return 0;
}