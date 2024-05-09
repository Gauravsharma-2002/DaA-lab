#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    // Ensure nums1 is smaller or equal in size compared to nums2
    if (m > n)
        return findMedianSortedArrays(nums2, nums1);

    int totalLength = m + n;
    int partitionSize = (totalLength + 1) / 2;

    int left = 0, right = m;

    while (left <= right) {
        int partitionA = left + (right - left) / 2;
        int partitionB = partitionSize - partitionA;

        int maxLeftA = (partitionA == 0) ? INT64_MIN : nums1[partitionA - 1];
        int minRightA = (partitionA == m) ? INT64_MAX : nums1[partitionA];

        int maxLeftB = (partitionB == 0) ? INT64_MIN : nums2[partitionB - 1];
        int minRightB = (partitionB == n) ? INT64_MAX : nums2[partitionB];

        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            // Found the correct partition
            if (totalLength % 2 == 0) {
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            } else {
                return max(maxLeftA, maxLeftB);
            }
        } else if (maxLeftA > minRightB) {
            // Move towards left in nums1
            right = partitionA - 1;
        } else {
            // Move towards right in nums1
            left = partitionA + 1;
        }
    }// Control should never reach here
    return -1;}
    void print (vector<int> &arr){
        int size = arr.size();
        for(int  i=0;i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
int main() {
vector<int> nums1 = {1, 5, 7, 10, 11, 15, 20};
vector<int> nums2 = {2, 3, 6, 8, 9, 12, 13, 14, 16, 17, 18, 19};
// function call with nums1 and nums2 as input argument

    double median = findMedianSortedArrays(nums1, nums2);
    print(nums1);
    print(nums2);
    cout << "Median of the two sorted arrays: " << median << endl;
    return 0;
}
