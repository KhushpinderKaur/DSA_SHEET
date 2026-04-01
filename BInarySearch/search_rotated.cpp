#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int k) {
       int n = nums.size();
       int low = 0;
       int high = n - 1;
       while(low < high){   //will terminate at low == high
         int mid = (low + high)/2;
         if(nums[mid] > nums[high]){
            low = mid + 1;
         }else{
            high = mid;
         }
       }
       int pi = low;

       low = 0; 
       high = n -1 ;
       if(nums[pi] >= k && k <= nums[high]){
          low = pi;
       }else{
          high = pi - 1;
       }

       while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] == k){
            return mid;
         }else if(nums[mid] > k){
            high = mid - 1;
         }else{
            low = mid + 1;
         }
       }
       return -1;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout << obj.search(nums, target);

    return 0;
}