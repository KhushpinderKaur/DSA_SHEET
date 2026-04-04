#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n -1;

        while(low < high){    //loop will stop at low == high
            int mid = low + (high - low)/2;
             
            //make mid even cause before single element pair start at even index and after that at odd index.
            if(mid % 2 == 1){
                mid--;   //CAN'T USE mid++ CAUSE THAT WILL CHANGE THE PAIRING PARTNER
            }

            if(nums[mid] == nums[mid+1]){  //pair starting at even as mid is even so left part don't have single element and move to right part
            low = mid + 2;
          }else{
                high = mid;  //element before mid or at mid
            }

        }
        return nums[low];   //or nums[high] that means search space has shrunk to exactly one element
    }
};

int main() {
    Solution obj;

    // Example test case
    vector<int> nums = {1,1,2,2,3,4,4,5,5};

    int result = obj.singleNonDuplicate(nums);

    cout << "Single non-duplicate element: " << result << endl;

    return 0;
}