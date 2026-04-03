#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                return true;
            }

            // shrink when duplicates
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            // left half sorted
            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target <= nums[mid]){
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // right half sorted
            else {
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 0;

    if(obj.search(nums, target)){
        cout << "Target found\n";
    } else {
        cout << "Target not found\n";
    }

    return 0;
}