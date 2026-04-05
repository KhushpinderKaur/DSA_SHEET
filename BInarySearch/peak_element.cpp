#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 1. Brute Force - Find Maximum Element (Always a Peak)
    int findPeakElement_BruteMax(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int index = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] > ans){
                ans = nums[i];
                index = i;
            }
        }
        return index;
    }

    // 2. Better Brute Force - Check Only Peak Condition
    int findPeakElement_Better(vector<int>& nums) {
        int n = nums.size();

        // Only one element
        if(n == 1) return 0;

        // First element is peak element
        if(nums[0] > nums[1]) return 0;

        // Last element is peak element
        if(nums[n-1] > nums[n-2]) return n-1;

        // Middle elements
        for(int i = 1; i < n-1; i++){
            if(nums[i] >= nums[i-1] && nums[i] >= nums[i+1]){
                return i;
            }
        }
        return -1;
    }

    // 3. Optimal - Binary Search
    int findPeakElement_Optimal(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        if(nums[0] > nums[1]) return 0;

        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 1, high = n - 2;

        while(low <= high){
            int mid = low + (high - low) / 2;

            // Peak found
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            // Peak is at right so Move right
            else if(nums[mid] < nums[mid+1]){
                low = mid + 1;
            }
            // Move left
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 3, 20, 4, 1, 0};

    cout << "Brute Force (Max Element Index): "
         << obj.findPeakElement_BruteMax(nums) << endl;

    cout << "Better Approach (Peak Index): "
         << obj.findPeakElement_Better(nums) << endl;

    cout << "Optimal (Binary Search Peak Index): "
         << obj.findPeakElement_Optimal(nums) << endl;

    return 0;
}