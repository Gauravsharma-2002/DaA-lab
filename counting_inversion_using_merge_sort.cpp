#include <iostream>
#include <vector>
using namespace std;
long long merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp(high - low + 1);
    long long inversionCount = 0; //inversion counter variable
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // Inversion found
            temp[k++] = arr[j++];
            inversionCount += mid - i + 1;} }
    while (i <= mid) {
        temp[k++] = arr[i++];}
    while (j <= high) {
        temp[k++] = arr[j++];}
    // Copy elements back to original array
    for (int idx = 0; idx < temp.size(); ++idx) {
        arr[low + idx] = temp[idx];}
    return inversionCount;}
// perform merge sort and count inversions
long long mergeSortAndCountInversions(vector<int>& arr, int low, int high) {
    long long inversionCount = 0;
    if (low < high) {
        int mid = low + (high - low) / 2;
        // Recursively counting inversions in left and right halves
        inversionCount += mergeSortAndCountInversions(arr, low, mid);
        inversionCount += mergeSortAndCountInversions(arr, mid + 1, high);
        // Merge the two sorted halves and count inversions
        inversionCount += merge(arr, low, mid, high);}
    return inversionCount;}
// Function to count inversions in an array using merge sort
long long countInversions(vector<int>& arr) {
    return mergeSortAndCountInversions(arr, 0, arr.size() - 1);
}
void print(vector<int> &arr){
    int size= arr.size();
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";}
    cout<<"\n";}
int main() {
  vector<int> arr = {8, 4, 2, 1, 9, 5, 7, 3, 6, 10};
    // Count inversions in the array
    print(arr);
    long long inversions = countInversions(arr);
    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
